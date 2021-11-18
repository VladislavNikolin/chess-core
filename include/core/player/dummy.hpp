#pragma once

#include "core/player/player.hpp"

namespace core::player
{
    class dummy : public player
    {
    public:
        core::board::move bestmove(core::board::position position);
    };
} // namespace core::player
