#pragma once

#include "core/board/move.hpp"
#include "core/board/position.hpp"

namespace core::player
{
    class player
    {
    public:
        virtual core::board::move bestmove(core::board::position position) = 0;
    };
} // namespace core::player
