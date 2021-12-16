#include <iostream>
#include <string>

#include "core/player/dummy.hpp"
#include "core/board/position.hpp"
#include "server.hpp"

int main()
{
    core::player::dummy dummy;
    uci::server server([&](auto fen) { //
        core::board::position position(fen);
        return dummy.bestmove(position).toAN();
    });

    server.start();
    return 0;
}
