#pragma once

#include "core/player/player.hpp"

namespace core::player
{
    class ai : public player
    {
    public:
        core::board::move bestmove(core::board::position position);
    };
} // namespace core::player
