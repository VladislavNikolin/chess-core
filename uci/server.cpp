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
    std::vector<std::string> moves;

    while (true)
    {
        std::istringstream request_ss;
        std::ostringstream response_ss;

        std::string request;
        std::getline(std::cin, request);
        _log << "[gui] " << request << std::endl;
        request_ss.str(request);

        std::string cmd;
        request_ss >> cmd;
        if (cmd == "uci")
            response_ss << "uciok";
        else if (cmd == "ucinewgame")
            continue;
        else if (cmd == "isready")
            response_ss << "readyok";
        else if (cmd == "position")
        {
            // position [fen <fenstring> | startpos ] moves <move1> .... <movei>
            std::string fen_or_startpos;
            std::string
                position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR",
                color = "w",
                castling = "KQkq",
                en_passant = "-",
                halfmove = "0",
                fullmove = "1";

            request_ss >> fen_or_startpos;
            if (fen_or_startpos == "fen")
                std::cin >> position >> color >> castling >> en_passant >> halfmove >> fullmove;

            moves.clear();
            std::string moves_or_eol;
            if (!request_ss.str().empty() && request_ss >> moves_or_eol && moves_or_eol == "moves")
                for (std::string move; request_ss >> move;)
                    moves.push_back(move);
            fen = position + " " + color + " " + castling + " " + en_passant + " " + halfmove + " " + fullmove;
        }
        else if (cmd == "go")
            response_ss << "bestmove " << _bestmove(fen, moves);
        else if (cmd == "quit")
            return;

        if (!response_ss.str().empty())
        {
            _log << "[engine] " << response_ss.str() << std::endl;
            std::cout << response_ss.str() << std::endl;
        }
    }
}
