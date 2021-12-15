#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

namespace uci
{
    class log
    {
    public:
    private:
        std::ofstream ofile;

    public:
        log(std::string filepath = "log.txt");
        ~log();
        std::ostream &operator<<(const std::string &message);
    };
} // namespace uci
