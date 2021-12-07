#pragma once

#include <cstdint>

namespace core::board
{
    struct point
    {
        uint8_t x;
        uint8_t y;

        bool operator==(const point &other) const;
    };
} // namespace core::board
