#pragma once

#include <tuple>

#include "core/board/point.hpp"

namespace core::board
{
    // reference: https://en.wikipedia.org/wiki/Algebraic_notation_(chess)
    struct move
    {
        core::board::point from;
        core::board::point to;

        bool operator==(const move &other) const;
    };
} // namespace core::board
