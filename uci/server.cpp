#include <iostream>
#include <sstream>
#include <tuple>

#include "server.hpp"
#include "log.hpp"

uci::server::server(bestmove_handler bestmove) : _bestmove(bestmove)
{
}

void uci::server::start()
{
    std::string fen;

    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream request(line);

        std::string cmd;
        request >> cmd;

        if (cmd == "uci")
            std::cout << "uciok" << std::endl;
        else if (cmd == "ucinewgame")
            continue;
        else if (cmd == "isready")
            std::cout << "readyok" << std::endl;
        else if (cmd == "position")
        {
            // position [fen <fenstring> | startpos ]  moves <move1> .... <movei>
            std::string fen_or_startpos;
            std::string
                position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR",
                color = "w",
                castling = "KQkq",
                en_passant = "-",
                halfmove = "0",
                fullmove = "1";

            request >> fen_or_startpos;
            if (fen_or_startpos == "fen")
                std::cin >> position >> color >> castling >> en_passant >> halfmove >> fullmove;

            fen = position + " " + color + " " + castling + " " + en_passant + " " + halfmove + " " + fullmove;
        }
        else if (cmd == "go")
            std::cout << "bestmove " << _bestmove(fen) << std::endl;
        else if (cmd == "quit")
            return;
    }
}
