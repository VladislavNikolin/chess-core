#include <iostream>

#include "core/board/board.hpp"
#include "core/player/ai.hpp"
#include "core/player/dummy.hpp"

int main(int argc, char const *argv[])
{
    auto white = core::player::ai();
    auto black = core::player::dummy();
    auto board = core::board::board();
    auto win = board.win();

    while ((winner = board.win()) == core::win::NO)
    {
        board.apply(white.bestmove(board.position()));
        board.apply(black.bestmove(board.position()));
    }

    std::cout << "and the winner is... " << (int) winner << std::endl;

    return 0;
}
