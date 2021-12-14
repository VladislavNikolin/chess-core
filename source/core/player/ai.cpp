#include <cstdlib>
#include <iostream>
#include <vector>

#include "core/player/ai.hpp"

#include "RLnet.h"
#include "neural/neuralnetwork.h"

QModel *m = new QModel({10,20,10,2},0.01);

core::board::move core::player::ai::bestmove(core::board::position position)
{
    auto moves = position.moves();
    std::vector<double> legal_moves(2,1);
    auto res = m->explore(legal_moves);
    return moves[res % moves.size()];
}
