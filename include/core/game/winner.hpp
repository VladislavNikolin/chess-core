#pragma once

#include <cstdint>

namespace core::game
{
    enum class winner : uint8_t
    {
        NONE = 0,
        WHITE,
        BLACK,
        DRAW,
    };
} // namespace core::game
