#pragma once

#include "core/board/point.hpp"

namespace core::board
{
    class move
    {
    public:
        move(core::board::point from, core::board::point to);
        core::board::point from();
        core::board::point to();
    private:
        core::board::point _from;
        core::board::point _to;
    };
} // namespace core::board
