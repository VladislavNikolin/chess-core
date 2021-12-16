#include <iostream>
#include <string>

#include "core/player/dummy.hpp"
#include "core/board/position.hpp"
#include "core/board/move.hpp"
#include "server.hpp"

int main()
{
    core::player::dummy dummy;
    uci::server server([&](auto fen, auto moves) { //
        core::board::position position(fen);
        for (auto move : moves)
            position.apply(core::board::move(move));
        return dummy.bestmove(position).toAN();
    });

    server.start();
    return 0;
}
