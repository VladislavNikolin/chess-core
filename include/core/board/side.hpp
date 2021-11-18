#pragma once

#include <cstdint>

namespace core::board
{
    class side
    {
    public:
        enum side_t : uint8_t
        {
            NONE,
            WHITE,
            BLACK,
        };

    private:
        side_t _side;

    public:
        side(side_t side);
        side operator!() const;
        bool operator==(const side& other) const;
    };
} // namespace core::board
