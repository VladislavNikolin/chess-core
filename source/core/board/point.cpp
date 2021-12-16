#include "core/board/point.hpp"

core::board::point::point(uint8_t x, uint8_t y) : _x(x), _y(y)
{
}

core::board::point::point(const std::string &an)
{
    std::string column = an.substr(0, 1);
    if (column == "a")
        _x = 1;
    else if (column == "b")
        _x = 2;
    else if (column == "c")
        _x = 3;
    else if (column == "d")
        _x = 4;
    else if (column == "e")
        _x = 5;
    else if (column == "f")
        _x = 6;
    else if (column == "g")
        _x = 7;
    else if (column == "h")
        _x = 8;
    _y = std::stoi(an.substr(1, 1));
}

bool core::board::point::operator==(const core::board::point &other) const
{
    return (_x == other._x) && (_y == other._y);
}

uint8_t &core::board::point::x()
{
    return _x;
}

uint8_t &core::board::point::y()
{
    return _y;
}

const uint8_t &core::board::point::x() const
{
    return _x;
}

const uint8_t &core::board::point::y() const
{
    return _y;
}

std::string core::board::point::to_string() const
{
    std::string column;
    switch (_x)
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

    return column + std::to_string(_y);
}
