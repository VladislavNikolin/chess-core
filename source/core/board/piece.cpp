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
    case QUEEN:
    case ROOK:
    case BISHOP:
    case KNIGHT:
    case PAWN:
        moves = std::vector<core::board::move>{};
    }

    return moves;
}
