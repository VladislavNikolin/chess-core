#include "core/board/position.hpp"

#include "range/v3/view.hpp"

void core::board::position::apply(core::board::move move)
{
	_side = !_side;
	core::board::piece::size_type n = _xy2n(move.from);
	core::board::piece _piece = _pieces(n);

	_pieces[n] = core::board::piece(core::board::piece::NONE, core::board::side::NONE);

	n = _xy2n(move.from);

	_pieces[n] = _piece;
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
	core::board::pieces::size_type from_n = _xy2n(move.from);
	core::board::pieces::size_type to_n = _xy2n(move.to);

	if (_pieces[to_n].is_my(_side)) return true;

	if (_pieces[from_n].get_piece_t() == core::board::piece::KNIGHT) return false;

	if (_pieces[from_n].get_piece_t() == core::board::piece::KING) {
		// checkmate, etc. there
		return false;
	}

	if (_pieces[from_n].get_piece_t() == core::board::piece::PAWN) {
		
		if (move.from.x == move.to.x && _pieces[to_n].get_piece_t() == core::board::piece::NONE) {
			if (_pieces[from_n].get_piece_t() == core::board::side::WHITE) {
				if (move.to.y - move.from.y == 2) {
					if (_pieces[_xy2n({ move.to.x, move.to.y - 1 }].get_piece_t() == core::board::piece::NONE) return false;
					return true;
				}
				return false;
			}
			if (_pieces[from_n].get_piece_t() == core::board::side::BLACK) {
				if (move.from.y - move.to.y == 2) {
					if (_pieces[_xy2n({ move.to.x, move.to.y + 1 }].get_piece_t() == core::board::piece::NONE) return false;
					return true;
				}
				return false;
			}
		}

		if (_pieces[to_n].get_piece_t() == core::board::piece::NONE) return true; // need add the take on the pass

		return false;
	}

	// ROOK QUEEN BISHOP logic

	return false;
}

core::board::point core::board::position::_n2xy(core::board::pieces::size_type n) const
{
	return core::board::point{(uint8_t)(n % 8), (uint8_t)(n / 8)};
}

core::board::pieces::size_type core::board::position::_xy2n(core::board::point xy) const
{
	return xy.y * 8 + xy.x - 1;
}
