#pragma once

#include <string>

#include "core/board/point.hpp"

namespace core::board
{
    // reference: https://en.wikipedia.org/wiki/Algebraic_notation_(chess)
    class move
    {
    private:
        core::board::point _from;
        core::board::point _to;

    public:
        move(core::board::point from, core::board::point to);
        move(const std::string &an);
        bool operator==(const move &other) const;
        core::board::point &from();
        core::board::point &to();
        const core::board::point &from() const;
        const core::board::point &to() const;
        std::string toAN() const;
    };
} // namespace core::board
