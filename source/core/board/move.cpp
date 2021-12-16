#include "core/board/move.hpp"

bool core::board::move::operator==(const core::board::move &other) const
{
    return (from == other.from) && (to == other.to);
}

std::string core::board::move::toAN()
{
    return from.to_string() + to.to_string();
}
