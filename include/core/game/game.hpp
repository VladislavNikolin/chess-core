#pragma once

#include <cstdint>

#include "core/board/move.hpp"
#include "core/board/position.hpp"
#include "core/board/piece.hpp"
#include "core/game/winner.hpp"

namespace core::game
{
    class game
    {
    private:
        core::board::position _position; // текущая ситуация на доске (позиция)

    public:
        bool finished();
        core::game::winner winner();
        void turn(core::board::move move);
        const core::board::position position() const;
    };
} // namespace core::game
