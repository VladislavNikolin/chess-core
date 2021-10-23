#pragma once

#include <array>
#include <cstdint>

namespace core::board
{
    enum class piece : uint8_t
    {
        NONE = 0,

        W_KING,
        W_QUEEN,
        W_ROOK,
        W_BISHOP,
        W_KNIGHT,
        W_PAWN,

        B_KING,
        B_QUEEN,
        B_ROOK,
        B_BISHOP,
        B_KNIGHT,
        B_PAWN,
    };

    using pieces = std::array<core::board::piece, 64>;
} // namespace core::board
