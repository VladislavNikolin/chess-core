#include "core/board/side.hpp"

core::board::side::side(core::board::side::side_t side) : _side(side) {}

core::board::side core::board::side::operator!() const
{
    switch (_side)
    {
    case NONE:
        return side(NONE);
    case WHITE:
        return side(BLACK);
    case BLACK:
        return side(WHITE);
    }
}

bool core::board::side::operator==(const side& other) const
{
    return other._side == _side;
}
