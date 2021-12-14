#include "core/board/piece.hpp"

core::board::piece::piece(piece_t piece, core::board::side side) : _piece(piece), _side(side) {
	moving = false;
}

core::board::piece core::board::piece::operator=(const core::board::piece& other)
{
	_piece = other._piece;
	_side = other._side;
	moving = other.moving;

	return *this;
}

bool core::board::piece::is_my(core::board::side side) const
{
	return side == _side;
}

core::board::piece::piece_t core::board::piece::get_piece_t() const
{
	return _piece;
}

bool core::board::piece::was_moving() const
{
	return moving;
}

std::vector<core::board::move> core::board::piece::get_moves(core::board::point from) const
{
	std::vector<core::board::move> moves;

	switch (_piece)
	{
	case NONE:
		moves = std::vector<core::board::move>{};
		break;
	case KING:
		for (int x = -1; x < 2; x++) {
			for (int y = -1; y < 2; y++) {
				if ((from.x == min_pos && x == -1)
					|| (from.y == min_pos && y == -1)
					|| (from.x == max_pos && x == 1)
					|| (from.y == max_pos && y == 1)
					|| (x == 0 && y == 0)) continue;

				moves.push_back({ from, { static_cast <uint8_t> (from.x + x), static_cast <uint8_t> (from.y + y) } });
			}
		}

		if (_side == core::board::side::WHITE && from.x == 5 && from.y == 1) {
			moves.push_back({ from, { static_cast <uint8_t> (from.x - 2), (from.y) } });
			moves.push_back({ from, { static_cast <uint8_t> (from.x + 2), (from.y) } });
		}

		if (_side == core::board::side::BLACK && from.x == 5 && from.y == 8) {
			moves.push_back({ from, { static_cast <uint8_t> (from.x - 2), (from.y) } });
			moves.push_back({ from, { static_cast <uint8_t> (from.x + 2), (from.y) } });
		}
		break;

	case QUEEN:
		for (uint8_t i = 1; i < 8; i++) {
			if (from.x + i <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + i), from.y} });
			if (from.x <= i) moves.push_back({ from, { static_cast <uint8_t> (from.x - i), static_cast <uint8_t> (from.y)} });
			if (from.y + i <= max_pos) moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y + i) } });
			if (from.y <= i) moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y - i) } });
		}

		for (int i = 1; i < 8; i++) {
			if (from.x + i <= max_pos && from.y + i < max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + i), static_cast <uint8_t> (from.y + i) } });
			if (from.x <= i && from.y + i <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x - i), static_cast <uint8_t> (from.y + i) } });
			if (from.x + i <= max_pos && from.y <= i) moves.push_back({ from, { static_cast <uint8_t> (from.x + i), static_cast <uint8_t> (from.y - i) } });
			if (from.x <= i && from.y <= i) moves.push_back({ from, { static_cast <uint8_t> (from.x - i), static_cast <uint8_t> (from.y - i) } });
		}
		break;

	case ROOK:
		for (int i = 1; i < 8; i++) {
			if (from.x + i <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + i), from.y} });
			if (from.x <= i) moves.push_back({ from, { static_cast <uint8_t> (from.x - i), from.y} });
			if (from.y + i <= max_pos) moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y + i) } });
			if (from.y <= i) moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y - i) } });
		}
		break;

	case BISHOP:
		for (int i = 1; i < 8; i++) {
			if (from.x + i <= max_pos && from.y + i < max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + i), static_cast <uint8_t> (from.y + i) } });
			if (from.x <= i && from.y + i <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x - i), static_cast <uint8_t> (from.y + i) } });
			if (from.x + i <= max_pos && from.y <= i) moves.push_back({ from, { static_cast <uint8_t> (from.x + i), static_cast <uint8_t> (from.y - i) } });
			if (from.x <= i && from.y <= i) moves.push_back({ from, { static_cast <uint8_t> (from.x - i), static_cast <uint8_t> (from.y - i) } });
		}
		break;

	case KNIGHT:
		if (from.x + 2 <= max_pos) {
			if (from.y <= 1) moves.push_back({ from, { static_cast <uint8_t> (from.x + 2), static_cast <uint8_t> (from.y - 1) } });
			if (from.y + 1 <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + 2), static_cast <uint8_t> (from.y + 1) } });
		}

		if (from.x <= 2) {
			if (from.y <= 1) moves.push_back({ from, { static_cast <uint8_t> (from.x - 2), static_cast <uint8_t> (from.y - 1) } });
			if (from.y + 1 <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x - 2), static_cast <uint8_t> (from.y + 1) } });
		}

		if (from.x + 1 <= max_pos) {
			if (from.y <= 2) moves.push_back({ from, { static_cast <uint8_t> (from.x + 1), static_cast <uint8_t> (from.y - 2) } });
			if (from.y + 2 <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + 1), static_cast <uint8_t> (from.y + 2) } });
		}

		if (from.x <= 1) {
			if (from.y <= 2) moves.push_back({ from, { static_cast <uint8_t> (from.x - 1), static_cast <uint8_t> (from.y - 2) } });
			if (from.y + 2 <= max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x - 1), static_cast <uint8_t> (from.y + 2) } });
		}

		break;
	case PAWN:
		if (_side == core::board::side::WHITE) {
			moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y + 1) } });
			if (from.y == min_pos + 1) moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y + 2) } });

			if (from.x != min_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x - 1), static_cast <uint8_t> (from.y + 1) } });
			if (from.x != max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + 1), static_cast <uint8_t> (from.y + 1) } });
		}

		if (_side == core::board::side::BLACK) {
			moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y - 1) } });
			if (from.y == max_pos - 1) moves.push_back({ from, { from.x, static_cast <uint8_t> (from.y - 2) } });

			if (from.x != min_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x - 1), static_cast <uint8_t> (from.y - 1) } });
			if (from.x != max_pos) moves.push_back({ from, { static_cast <uint8_t> (from.x + 1), static_cast <uint8_t> (from.y - 1) } });
		}
		break;
	}

	return moves;
}
