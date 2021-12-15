#pragma once

#include <cstdint>
#include <string>

namespace core::board
{
    struct point
    {
        uint8_t x;
        uint8_t y;

        bool operator==(const point &other) const;
        std::string to_string();
    };
} // namespace core::board
