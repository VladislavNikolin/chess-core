#include "core/board/position.hpp"

#include "range/v3/view.hpp"

void core::board::position::apply(core::board::move move)
{
	_side = !_side;
	core::board::pieces::size_type n = _xy2n(move.from);
	core::board::piece _piece = _pieces[n];

	//_pieces[n] = core::board::piece(core::board::piece::NONE, core::board::side::NONE);

	n = _xy2n(move.from);

	//_pieces[n] = _piece;
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
		| ranges::views::enumerate			//
		| ranges::views::filter(is_my)		//
		| ranges::views::transform(to_moves) //
		| ranges::views::cache1				// hate cxx
		| ranges::views::join				//
		| ranges::views::filter(is_bad_move) //
		| ranges::to<std::vector>();
};

bool core::board::position::_is_bad_move(core::board::move move) const
{
	switch (_pieces[_xy2n({ move.from.x, move.from.y })].get_piece_t())
	{
	case core::board::piece::NONE:
		return true;
	case core::board::piece::KING:
		return _king_ckeck(move);
	case core::board::piece::QUEEN:
		return _queen_ckeck(move);
	case core::board::piece::ROOK:
		return _rook_ckeck(move);
	case core::board::piece::BISHOP:
		return _bishop_ckeck(move);
	case core::board::piece::KNIGHT:
		return _knight_ckeck(move);
	case core::board::piece::PAWN:
		return _pawn_ckeck(move);
	}

	return true;
}

bool core::board::position::_pawn_ckeck(core::board::move move) const
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

	if (_pieces[to_n].get_piece_t() == core::board::piece::NONE) return true; // need add the take on the pass

	return false;
}

bool core::board::position::_knight_ckeck(core::board::move move) const
{
	return false;
}

bool core::board::position::_king_ckeck(core::board::move move) const
{
	return false;
}

bool core::board::position::_rook_ckeck(core::board::move move) const
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
			if (_pieces[_xy2n({ static_cast <uint8_t> (move.to.x, y) })].get_piece_t() != core::board::piece::NONE) return true;
		}

		return false;
	}
}

bool core::board::position::_bishop_ckeck(core::board::move move) const
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

bool core::board::position::_queen_ckeck(core::board::move move) const
{
	return _bishop_ckeck(move) && _rook_ckeck(move);
}

core::board::point core::board::position::_n2xy(core::board::pieces::size_type n) const
{
	return core::board::point{ (uint8_t)(n % 8), (uint8_t)(n / 8) };
}

core::board::pieces::size_type core::board::position::_xy2n(core::board::point xy) const
{
	return xy.y * 8 + xy.x - 1;
}
