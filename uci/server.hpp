#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <tuple>

#include "log.hpp"

namespace uci
{
    class server
    {
    public:
        using bestmove_handler = std::function<std::string(std::string)>;

    private:
        // enum cmd : uint8_t
        // {
        //     UNKNOWN,
        //     UCI,
        //     UCINEWGAME,
        //     ISREADY,
        //     POSITION,
        //     GO,
        //     QUIT,
        // };

        uci::log _log;
        bestmove_handler _bestmove;

    public:
        server(bestmove_handler h);
        void start();
    };
} // namespace uci
