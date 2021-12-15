#pragma once

#include "core/board/move.hpp"
#include "core/board/point.hpp"
#include "core/board/side.hpp"

#include <array>
#include <cstdint>
#include <vector>

namespace core::board
{
    class piece
    {
    public:
        enum piece_t : uint8_t
        {
            NONE,
            KING,
            QUEEN,
            ROOK,
            BISHOP,
            KNIGHT,
            PAWN,
        };

    private:
        piece_t _piece = NONE;
        core::board::side _side = core::board::side::NONE;

        bool moving = false;
        const int max_pos = 8;
        const int min_pos = 1;

    public:
        piece();
        piece(const char &an);
        piece(const piece &other);
        piece(piece_t piece, core::board::side side);
        piece operator=(const piece &other);
        bool operator==(const piece& other) const;
        bool is_my(core::board::side side) const;
        bool was_moving() const;
        piece_t get_piece_t() const;
        std::vector<core::board::move> get_moves(core::board::point from) const;
    };

    using pieces = std::array<piece, 64>;
} // namespace core::board
