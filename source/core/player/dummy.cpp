#include <cstdlib>

#include "core/player/dummy.hpp"

core::board::move core::player::dummy::bestmove(core::board::position position)
{
    auto moves = position.moves();
    return moves[std::rand() % moves.size()];
}

