#include <cstdlib>

#include "core/player/ai.hpp"

core::board::move core::player::ai::bestmove(core::board::position position)
{
    auto moves = position.moves();
    return moves[std::rand() % moves.size()];
}

