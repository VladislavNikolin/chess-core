#include "core/board/point.hpp"

bool core::board::point::operator==(const core::board::point &other) const
{
    return (x == other.x) && (y == other.y);
}

std::string core::board::point::to_string()
{
    std::string column;
    switch (x)
    {
    case 1:
        column = "a";
        break;
    case 2:
        column = "b";
        break;
    case 3:
        column = "c";
        break;
    case 4:
        column = "d";
        break;
    case 5:
        column = "e";
        break;
    case 6:
        column = "f";
        break;
    case 7:
        column = "g";
        break;
    case 8:
        column = "h";
        break;
    }

    return column + std::to_string(y);
}
