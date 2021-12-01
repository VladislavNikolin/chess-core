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
		moves = std::vector<core::board::move>{
			{from, {from.x + 1, from.y}},
			{from, {from.x - 1, from.y}},
			{from, {from.x, from.y + 1}},
			{from, {from.x, from.y - 1}},
			{from, {from.x + 1, from.y + 1}},
			{from, {from.x + 1, from.y - 1}},
			{from, {from.x - 1, from.y + 1}},
			{from, {from.x - 1, from.y - 1}},
		};
	case QUEEN:
		moves = std::vector<core::board::move>{
			{ from, { from.x + 1, from.y } },
			{ from, { from.x + 2, from.y } },
			{ from, { from.x + 3, from.y } },
			{ from, { from.x + 4, from.y } },
			{ from, { from.x + 5, from.y } },
			{ from, { from.x + 6, from.y } },
			{ from, { from.x + 7, from.y } },
			{ from, { from.x, from.y + 1 } },
			{ from, { from.x, from.y + 2 } },
			{ from, { from.x, from.y + 3 } },
			{ from, { from.x, from.y + 4 } },
			{ from, { from.x, from.y + 5 } },
			{ from, { from.x, from.y + 6 } },
			{ from, { from.x, from.y + 7 } },
			{ from, { from.x - 1, from.y } },
			{ from, { from.x - 2, from.y } },
			{ from, { from.x - 3, from.y } },
			{ from, { from.x - 4, from.y } },
			{ from, { from.x - 5, from.y } },
			{ from, { from.x - 6, from.y } },
			{ from, { from.x - 7, from.y } },
			{ from, { from.x, from.y - 1 } },
			{ from, { from.x, from.y - 2 } },
			{ from, { from.x, from.y - 3 } },
			{ from, { from.x, from.y - 4 } },
			{ from, { from.x, from.y - 5 } },
			{ from, { from.x, from.y - 6 } },
			{ from, { from.x, from.y - 7 } },
			{ from, { from.x + 1, from.y + 1 } },
			{ from, { from.x + 2, from.y + 2 } },
			{ from, { from.x + 3, from.y + 3 } },
			{ from, { from.x + 4, from.y + 4 } },
			{ from, { from.x + 5, from.y + 5 } },
			{ from, { from.x + 6, from.y + 6 } },
			{ from, { from.x + 7, from.y + 7 } },
			{ from, { from.x - 1, from.y + 1 } },
			{ from, { from.x - 2, from.y + 2 } },
			{ from, { from.x - 3, from.y + 3 } },
			{ from, { from.x - 4, from.y + 4 } },
			{ from, { from.x - 5, from.y + 5 } },
			{ from, { from.x - 6, from.y + 6 } },
			{ from, { from.x - 7, from.y + 7 } },
			{ from, { from.x + 1, from.y - 1 } },
			{ from, { from.x + 2, from.y - 2 } },
			{ from, { from.x + 3, from.y - 3 } },
			{ from, { from.x + 4, from.y - 4 } },
			{ from, { from.x + 5, from.y - 5 } },
			{ from, { from.x + 6, from.y - 6 } },
			{ from, { from.x + 7, from.y - 7 } },
			{ from, { from.x - 1, from.y - 1 } },
			{ from, { from.x - 2, from.y - 2 } },
			{ from, { from.x - 3, from.y - 3 } },
			{ from, { from.x - 4, from.y - 4 } },
			{ from, { from.x - 5, from.y - 5 } },
			{ from, { from.x - 6, from.y - 6 } },
			{ from, { from.x - 7, from.y - 7 } },
		};
	case ROOK:
		moves = std::vector<core::board::move>{
			{ from, { from.x + 1, from.y } },
			{ from, { from.x + 2, from.y } },
			{ from, { from.x + 3, from.y } },
			{ from, { from.x + 4, from.y } },
			{ from, { from.x + 5, from.y } },
			{ from, { from.x + 6, from.y } },
			{ from, { from.x + 7, from.y } },
			{ from, { from.x, from.y + 1 } },
			{ from, { from.x, from.y + 2 } },
			{ from, { from.x, from.y + 3 } },
			{ from, { from.x, from.y + 4 } },
			{ from, { from.x, from.y + 5 } },
			{ from, { from.x, from.y + 6 } },
			{ from, { from.x, from.y + 7 } },
			{ from, { from.x - 1, from.y } },
			{ from, { from.x - 2, from.y } },
			{ from, { from.x - 3, from.y } },
			{ from, { from.x - 4, from.y } },
			{ from, { from.x - 5, from.y } },
			{ from, { from.x - 6, from.y } },
			{ from, { from.x - 7, from.y } },
			{ from, { from.x, from.y - 1 } },
			{ from, { from.x, from.y - 2 } },
			{ from, { from.x, from.y - 3 } },
			{ from, { from.x, from.y - 4 } },
			{ from, { from.x, from.y - 5 } },
			{ from, { from.x, from.y - 6 } },
			{ from, { from.x, from.y - 7 } },
		};
	case BISHOP:
		moves = std::vector<core::board::move>{
			{ from, { from.x + 1, from.y + 1 } },
			{ from, { from.x + 2, from.y + 2 } },
			{ from, { from.x + 3, from.y + 3 } },
			{ from, { from.x + 4, from.y + 4 } },
			{ from, { from.x + 5, from.y + 5 } },
			{ from, { from.x + 6, from.y + 6 } },
			{ from, { from.x + 7, from.y + 7 } },
			{ from, { from.x - 1, from.y + 1 } },
			{ from, { from.x - 2, from.y + 2 } },
			{ from, { from.x - 3, from.y + 3 } },
			{ from, { from.x - 4, from.y + 4 } },
			{ from, { from.x - 5, from.y + 5 } },
			{ from, { from.x - 6, from.y + 6 } },
			{ from, { from.x - 7, from.y + 7 } },
			{ from, { from.x + 1, from.y - 1 } },
			{ from, { from.x + 2, from.y - 2 } },
			{ from, { from.x + 3, from.y - 3 } },
			{ from, { from.x + 4, from.y - 4 } },
			{ from, { from.x + 5, from.y - 5 } },
			{ from, { from.x + 6, from.y - 6 } },
			{ from, { from.x + 7, from.y - 7 } },
			{ from, { from.x - 1, from.y - 1 } },
			{ from, { from.x - 2, from.y - 2 } },
			{ from, { from.x - 3, from.y - 3 } },
			{ from, { from.x - 4, from.y - 4 } },
			{ from, { from.x - 5, from.y - 5 } },
			{ from, { from.x - 6, from.y - 6 } },
			{ from, { from.x - 7, from.y - 7 } },
		};
	case KNIGHT:
		moves = std::vector<core::board::move>{
			{ from, { from.x + 2, from.y - 1 } },
			{ from, { from.x + 2, from.y + 1 } },
			{ from, { from.x - 2, from.y - 1 } },
			{ from, { from.x - 2, from.y + 1 } },
			{ from, { from.x + 1, from.y + 2 } },
			{ from, { from.x + 1, from.y - 2 } },
			{ from, { from.x - 1, from.y + 2 } },
			{ from, { from.x - 1, from.y - 2 } },
		};
	case PAWN:
		if (_side == core::board::side::WHITE) {
			moves.push_back({ from, { from.x, from.y + 1 } });
			if (from.y == 2) moves.push_back({ from, { from.x, from.y + 2 } });
		}
																				//Пока не едят
		if (_side == core::board::side::BLACK) {
			moves.push_back({ from, { from.x, from.y - 1 } });
			if (from.y == 7) moves.push_back({ from, { from.x, from.y - 2 } });
		}
	}

	return moves;
}
