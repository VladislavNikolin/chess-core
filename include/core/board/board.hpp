#pragma once

#include <cstdint>

#include "core/win.hpp"
#include "core/board/move.hpp"
#include "core/board/position.hpp"
#include "core/board/piece.hpp"

namespace core::board
{
    class board
    {
    public:
        core::win win();
        core::board::position position();
        void apply(core::board::move move);

    private:
        core::board::pieces _pieces = {
            core::board::piece::B_ROOK,
            core::board::piece::B_KNIGHT,
            core::board::piece::B_BISHOP,
            core::board::piece::B_QUEEN,
            core::board::piece::B_KING,
            core::board::piece::B_BISHOP,
            core::board::piece::B_KNIGHT,
            core::board::piece::B_ROOK,
            core::board::piece::B_PAWN,
            core::board::piece::B_PAWN,
            core::board::piece::B_PAWN,
            core::board::piece::B_PAWN,
            core::board::piece::B_PAWN,
            core::board::piece::B_PAWN,
            core::board::piece::B_PAWN,
            core::board::piece::B_PAWN,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::NONE,
            core::board::piece::W_ROOK,
            core::board::piece::W_KNIGHT,
            core::board::piece::W_BISHOP,
            core::board::piece::W_QUEEN,
            core::board::piece::W_KING,
            core::board::piece::W_BISHOP,
            core::board::piece::W_KNIGHT,
            core::board::piece::W_ROOK,
            core::board::piece::W_PAWN,
            core::board::piece::W_PAWN,
            core::board::piece::W_PAWN,
            core::board::piece::W_PAWN,
            core::board::piece::W_PAWN,
            core::board::piece::W_PAWN,
            core::board::piece::W_PAWN,
            core::board::piece::W_PAWN,
        };
    };
} // namespace core::board
