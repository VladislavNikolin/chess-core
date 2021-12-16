#pragma once

#include <cstdint>
#include <string>

namespace core::board
{
    class point
    {
    private:
        uint8_t _x;
        uint8_t _y;

    public:
        point(uint8_t x, uint8_t y);
        point(const std::string &an);
        bool operator==(const point &other) const;
        uint8_t &x();
        uint8_t &y();
        const uint8_t &x() const;
        const uint8_t &y() const;
        std::string to_string() const;
    };
} // namespace core::board
