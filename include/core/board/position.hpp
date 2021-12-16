#pragma once

#include <array>
#include <cstdint>
#include <string>
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
        core::board::point w_king_pos = { 5, 1 };
        core::board::point b_king_pos = { 5, 8 };
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
        position(std::string fen);
        void apply(core::board::move move);
        std::vector<core::board::move> moves() const;

    private:
        move last_move;
        core::board::piece last_piece;

        bool _is_bad_move(move) const;

        bool _is_shah(move) const;
        bool _pawn_check(move) const;
        bool _knight_check(move) const;
        bool _king_check(move) const;
        bool _rook_check(move) const;
        bool _bishop_check(move) const;
        bool _queen_check(move) const;

        bool _pawn_attack_filter(core::board::move move) const;
        std::vector<core::board::move> attacks() const;

        core::board::point _n2xy(core::board::pieces::size_type n) const;
        core::board::pieces::size_type _xy2n(core::board::point xy) const;
    };
} // namespace core::board
