#include "log.hpp"

uci::log::log(std::string filepath)
{
    ofile.open(filepath);
}

uci::log::~log()
{
    ofile.close();
}

std::ostream &uci::log::operator<<(const std::string &message)
{
    return ofile << message << std::endl;
}
