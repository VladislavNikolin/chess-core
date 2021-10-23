#pragma once

#include <array>
#include <vector>

#include "core/side.hpp"
#include "core/board/move.hpp"
#include "core/board/piece.hpp"

namespace core::board
{
    class position
    {
    public:
        position(core::board::pieces pieces, core::side side);
        core::side side();
        std::vector<core::board::point> pieces();
        std::vector<core::board::move> moves(core::board::point from);
    private:
        core::board::pieces _pieces;
        core::side _side;
    };
} // namespace core::board
