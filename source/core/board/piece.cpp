#include "core/board/piece.hpp"

core::board::piece::piece(piece_t piece, core::board::side side) : _piece(piece), _side(side) {}

bool core::board::piece::is_my(core::board::side side) const
{
	return side == _side;
}

std::vector<core::board::move> core::board::piece::get_moves(core::board::point from) const
{
	std::vector<core::board::move> moves;

	switch (_piece)
	{
	case NONE:
		moves = std::vector<core::board::move>{};
	case KING:
		for (int x = -1; x < 2; x++) {
			for (int y = -1; y < 2; y++) {
				if ((from.x == min_pos && x == -1) 
					|| from.y == min_pos && y == -1)
					|| (from.x == max_pos && x == 1) 
					|| (from.y == max_pos && y == 1)
					|| (x == 0 && y == 0)) continue;

					moves.push_back({ from, { from.x + x, from.y + y } });
			}
		}
		break;

	case QUEEN:
		for (int i = 1; i < 8; i++) {
			if (from.x + i <= max_pos) moves.push_back({ from, { from.x + i, from.y} });
			if (from.x <= i) moves.push_back({ from, { from.x - i, from.y} });
			if (from.y + i <= max_pos) moves.push_back({ from, { from.x, from.y + i } });
			if (from.y <= i) moves.push_back({ from, { from.x, from.y - i } });
		}

		for (int i = 1; i < 8; i++) {
			if (from.x + i <= max_pos && from.y + i < m = x_pos) moves.push_back({ from, { from.x + i, from.y + i } });
			if (from.x <= i && from.y + i <= max_pos) moves.push_back({ from, { from.x - i, from.y + i } });
			if (from.x + i <= max_pos && from.y <= i) moves.push_back({ from, { from.x + i, from.y - i } });
			if (from.x <= i && from.y <= i) moves.push_back({ from, { from.x - i, from.y - i } });
		}
		break;

	case ROOK:
		for (int i = 1; i < 8; i++) {
			if (from.x + i <= max_pos) moves.push_back({ from, { from.x + i, from.y} });
			if (from.x <= i) moves.push_back({ from, { from.x - i, from.y} });
			if (from.y + i <= max_pos) moves.push_back({ from, { from.x, from.y + i } });
			if (from.y <= i) moves.push_back({ from, { from.x, from.y - i } });
		}
		break;

	case BISHOP:
		for (int i = 1; i < 8; i++) {
			if (from.x + i <= max_pos && from.y + i < m=x_pos) moves.push_back({ from, { from.x + i, from.y + i } });
			if (from.x <= i && from.y + i <= max_pos) moves.push_back({ from, { from.x - i, from.y + i } });
			if (from.x + i <= max_pos && from.y <= i) moves.push_back({ from, { from.x + i, from.y - i } });
			if (from.x <= i && from.y <= i) moves.push_back({ from, { from.x - i, from.y - i } });
		}
		break;

	case KNIGHT:
			if (from.x + 2 <= max_pos) {

			}
			{ from, { from.x + 2, from.y - 1 } },
			{ from, { from.x + 2, from.y + 1 } },
			{ from, { from.x - 2, from.y - 1 } },
			{ from, { from.x - 2, from.y + 1 } },
			{ from, { from.x + 1, from.y + 2 } },
			{ from, { from.x + 1, from.y - 2 } },
			{ from, { from.x - 1, from.y + 2 } },
			{ from, { from.x - 1, from.y - 2 } },

	case PAWN:
		if (_side == core::board::side::WHITE) {
			moves.push_back({ from, { from.x, from.y + 1 } });
			if (from.y == min_pos + 1) moves.push_back({ from, { from.x, from.y + 2 } });
		}
																				//Пока не едят
		if (_side == core::board::side::BLACK) {
			moves.push_back({ from, { from.x, from.y - 1 } });
			if (from.y == max_pos - 1) moves.push_back({ from, { from.x, from.y - 2 } });
		}
	}

	return moves;
}
