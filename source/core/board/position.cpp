#include <sstream>

#include "core/board/position.hpp"

#include "range/v3/view.hpp"

core::board::position::position(std::string fen)
{
    std::stringstream fen_ss(fen);
    std::string position, color, castling, en_passant, halfmove, fullmove;
    fen_ss >> position >> color >> castling >> en_passant >> halfmove >> fullmove;

    int i = 0;
    for (auto row : ranges::views::split(position, "/"))
    {
        for (auto piece : row)
        {
            if (std::isdigit(piece)) // empty cells
                i += std::stoi(std::to_string(piece));
            else
                _pieces[i++] = core::board::piece(piece);
        }
    }
    _side = (color == "w") ? core::board::side::WHITE : core::board::side::BLACK;
}

void core::board::position::apply(core::board::move move)
{
    _side = !_side;
    core::board::pieces::size_type n = _xy2n(move.from);
    last_piece = _pieces[n];

	if (_pieces[_xy2n({ move.from.x, move.from.y })].get_piece_t() == core::board::piece::KING && _side == core::board::side::WHITE) {
		w_king_pos.x = move.to.x;
		w_king_pos.y = move.to.y;
	}

	if (_pieces[_xy2n({ move.from.x, move.from.y })].get_piece_t() == core::board::piece::KING && _side == core::board::side::BLACK) {
		b_king_pos.x = move.to.x;
		b_king_pos.y = move.to.y;
	}

	_pieces[n] = core::board::piece(core::board::piece::NONE, core::board::side::NONE);

    n = _xy2n(move.to);

    _pieces[n] = last_piece;

    //рокировка и взятие на проходе

    last_move = move;
}

std::vector<core::board::move> core::board::position::moves() const
{
	auto is_my = [&](auto p)
	{ return p.second.is_my(_side); };
	auto to_moves = [&](auto p)
	{ return p.second.get_moves(_n2xy(p.first)); };
	auto is_bad_move = [&](auto m)
	{ return _is_bad_move(m); };

	return _pieces								//
		| ranges::views::enumerate				//
		| ranges::views::filter(is_my)			//
		| ranges::views::transform(to_moves)	//
		| ranges::views::cache1					// hate cxx
		| ranges::views::join					//
		| ranges::views::filter(is_bad_move)	//
		| ranges::to<std::vector>();
};

std::vector<core::board::move> core::board::position::attacks() const
{
	auto is_my = [&](auto p)
	{ return p.second.is_my(_side); };
	auto to_moves = [&](auto p)
	{ return p.second.get_moves(_n2xy(p.first)); };
	auto is_bad_move = [&](auto m)
	{ return _is_bad_move(m); };
	auto pawn_attack_filter = [&](auto n)
	{ return _pawn_attack_filter(n); };

	return _pieces									//
		| ranges::views::enumerate					//
		| ranges::views::filter(is_my)				//
		| ranges::views::transform(to_moves)		//
		| ranges::views::cache1						// hate cxx
		| ranges::views::join						//
		| ranges::views::filter(pawn_attack_filter) //
		| ranges::views::filter(is_bad_move)		//
		| ranges::to<std::vector>();
};

bool core::board::position::_pawn_attack_filter(core::board::move move) const
{
	if (_pieces[_xy2n({ move.from.x, move.from.y })].get_piece_t() == core::board::piece::PAWN && move.from.x == move.to.x) return true;

	return false;
}

bool core::board::position::_is_bad_move(core::board::move move) const
{

	switch (_pieces[_xy2n({ move.from.x, move.from.y })].get_piece_t())
	{
	case core::board::piece::NONE:
		return true;
	case core::board::piece::KING:
		return _king_check(move);
	case core::board::piece::QUEEN:
		return _queen_check(move);
	case core::board::piece::ROOK:
		return _rook_check(move);
	case core::board::piece::BISHOP:
		return _bishop_check(move);
	case core::board::piece::KNIGHT:
		return _knight_check(move);
	case core::board::piece::PAWN:
		return _pawn_check(move);
	}

	return true;
}

bool core::board::position::_is_shah(core::board::move move) const
{
	uint8_t x;
	uint8_t y;

	if (_side == core::board::side::BLACK) {
		x = w_king_pos.x;
		y = w_king_pos.y;
	}
	else {
		x = b_king_pos.x;
		y = b_king_pos.y;
	}

	auto _attacks = attacks();

	for (size_t i = 0; i < _attacks.size(); i++) {
		if (_attacks[i].to.x == x && _attacks[i].to.y == y) return true;
	}
	return false;
}

bool core::board::position::_pawn_check(core::board::move move) const
{

	core::board::pieces::size_type from_n = _xy2n(move.from);
	core::board::pieces::size_type to_n = _xy2n(move.to);

	if (move.from.x == move.to.x && _pieces[to_n].get_piece_t() == core::board::piece::NONE) {
		if (_pieces[from_n].get_piece_t() == core::board::side::WHITE) {
			if (move.to.y - move.from.y == 2) {
				if (_pieces[_xy2n({ move.to.x, static_cast <uint8_t> (move.to.y - 1) })].get_piece_t() == core::board::piece::NONE) return false;
				return true;
			}
			return false;
		}
		if (_pieces[from_n].get_piece_t() == core::board::side::BLACK) {
			if (move.from.y - move.to.y == 2) {
				if (_pieces[_xy2n({ move.to.x, static_cast <uint8_t> (move.to.y + 1) })].get_piece_t() == core::board::piece::NONE) return false;
				return true;
			}
			return false;
		}
	}

	if (_pieces[to_n].get_piece_t() == core::board::piece::PAWN && (last_move.from.x == move.to.x)
		&& (last_move.from.y == move.to.y + 1) && (last_move.to.y == move.from.y)
		&& (last_move.from.y == 7) && last_piece.get_piece_t() == core::board::piece::PAWN
		&& _pieces[to_n].is_my(core::board::side::WHITE)) return false;

	if (_pieces[to_n].get_piece_t() == core::board::piece::PAWN && (last_move.from.x == move.to.x)
		&& (last_move.from.y == move.to.y - 1) && (last_move.to.y == move.from.y)
		&& (last_move.from.y == 2) && last_piece.get_piece_t() == core::board::piece::PAWN
		&& _pieces[to_n].is_my(core::board::side::BLACK)) return false;

	if (_pieces[to_n].get_piece_t() == core::board::piece::NONE) return true;

	return false;
}

bool core::board::position::_knight_check(core::board::move move) const
{
    return false;
}

bool core::board::position::_king_check(core::board::move move) const
{
	if (move.from.x == 5 && move.to.x == 3) {
		if (!_pieces[_xy2n({ move.from.x, move.from.y })].was_moving() && !_pieces[_xy2n({ 1, move.from.y })].was_moving()) return true;
	}

	if (move.from.x == 5 && move.to.x == 7) {
		if (!_pieces[_xy2n({ move.from.x, move.from.y })].was_moving() && !_pieces[_xy2n({ 8, move.from.y })].was_moving()) return true;
	}

	return false;
}

bool core::board::position::_rook_check(core::board::move move) const
{

	int max;
	int min;

	if (move.from.y == move.to.y) {
		if (move.from.x < move.to.x) {
			max = move.to.x;
			min = move.from.x;
		}
		else {
			max = move.from.x;
			min = move.to.x;
		}

		for (uint8_t x = min; x < max; x++) {
			if (_pieces[_xy2n({ x, move.to.y })].get_piece_t() != core::board::piece::NONE) return true;
		}

		return false;
	}

	if (move.from.x == move.to.x) {
		if (move.from.y < move.to.y) {
			max = move.to.y;
			min = move.from.y;
		}
		else {
			max = move.from.y;
			min = move.to.y;
		}

		for (int y = min; y < max; y++) {
			if (_pieces[_xy2n({ move.to.x, static_cast <uint8_t> (y) })].get_piece_t() != core::board::piece::NONE) return true;
		}

		return false;
	}
	return true;
}

bool core::board::position::_bishop_check(core::board::move move) const
{

	if (move.from.x < move.to.x) {
		if (move.from.y < move.to.y) {
			for (uint8_t i = 1; i < move.to.y - move.from.y; i++) {
				if (_pieces[_xy2n({ static_cast <uint8_t> (move.from.x + i), static_cast <uint8_t> (move.from.y + i) })].get_piece_t() != core::board::piece::NONE) return true;
			}
		}
		else {
			for (uint8_t i = 1; i < move.from.y - move.to.y; i++) {
				if (_pieces[_xy2n({ static_cast <uint8_t> (move.from.x + i), static_cast <uint8_t> (move.from.y - i) })].get_piece_t() != core::board::piece::NONE) return true;
			}
		}
	}
	else {
		if (move.from.y < move.to.y) {
			for (int i = 1; i < move.to.y - move.from.y; i++) {
				if (_pieces[_xy2n({ static_cast <uint8_t> (move.from.x - i), static_cast <uint8_t> (move.from.y + i) })].get_piece_t() != core::board::piece::NONE) return true;
			}
		}
		else {
			for (int i = 1; i < move.from.y - move.to.y; i++) {
				if (_pieces[_xy2n({ static_cast <uint8_t> (move.from.x - i), static_cast <uint8_t> (move.from.y - i) })].get_piece_t() != core::board::piece::NONE) return true;
			}
		}
	}

	return false;
}

bool core::board::position::_queen_check(core::board::move move) const
{
	return _bishop_check(move) || _rook_check(move);
}

core::board::point core::board::position::_n2xy(core::board::pieces::size_type n) const
{
    return core::board::point{(uint8_t)(n % 8), (uint8_t)(n / 8)};
}

core::board::pieces::size_type core::board::position::_xy2n(core::board::point xy) const
{
    return xy.y * 8 + xy.x - 1;
}
