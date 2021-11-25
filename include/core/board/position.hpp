#pragma once

#include <array>
#include <cstdint>
#include <vector>

#include "core/board/move.hpp"
#include "core/board/piece.hpp"
#include "core/board/side.hpp"

namespace core::board
{
    // reference: https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
    class position
    {
    private:
        core::board::side _side = core::board::side::WHITE;
        core::board::pieces _pieces = {
            core::board::piece(core::board::piece::ROOK, core::board::side::BLACK),
            core::board::piece(core::board::piece::KNIGHT, core::board::side::BLACK),
            core::board::piece(core::board::piece::BISHOP, core::board::side::BLACK),
            core::board::piece(core::board::piece::QUEEN, core::board::side::BLACK),
            core::board::piece(core::board::piece::KING, core::board::side::BLACK),
            core::board::piece(core::board::piece::BISHOP, core::board::side::BLACK),
            core::board::piece(core::board::piece::KNIGHT, core::board::side::BLACK),
            core::board::piece(core::board::piece::ROOK, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::PAWN, core::board::side::BLACK),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::NONE, core::board::side::NONE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::PAWN, core::board::side::WHITE),
            core::board::piece(core::board::piece::ROOK, core::board::side::WHITE),
            core::board::piece(core::board::piece::KNIGHT, core::board::side::WHITE),
            core::board::piece(core::board::piece::BISHOP, core::board::side::WHITE),
            core::board::piece(core::board::piece::QUEEN, core::board::side::WHITE),
            core::board::piece(core::board::piece::KING, core::board::side::WHITE),
            core::board::piece(core::board::piece::BISHOP, core::board::side::WHITE),
            core::board::piece(core::board::piece::KNIGHT, core::board::side::WHITE),
            core::board::piece(core::board::piece::ROOK, core::board::side::WHITE),
        };

    public:
        void apply(core::board::move move);
        std::vector<core::board::move> moves() const;
    
    private:
        bool _is_bad_move(move) const;
        core::board::point _n2xy(core::board::pieces::size_type n) const;
        core::board::pieces::size_type _xy2n(core::board::point xy) const;
    };
} // namespace core::board
