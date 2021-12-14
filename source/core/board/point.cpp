#include "core/board/point.hpp"

bool core::board::point::operator==(const core::board::point &other) const
{
    return (x == other.x) && (y == other.y);
}
