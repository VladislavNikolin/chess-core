#include <iostream>

#include "core/game/game.hpp"
#include "core/player/ai.hpp"
#include "core/player/dummy.hpp"

int main(int argc, char const *argv[])
{
    auto white = core::player::ai();
    auto black = core::player::dummy();
    auto game = core::game::game();

    while (!game.finished())
    {
        game.turn(white.bestmove(game.position()));
        game.turn(black.bestmove(game.position()));
    }

    std::cout << "and the winner is... " << (int) game.winner() << std::endl;

    return 0;
}
