#include "core/board/move.hpp"

core::board::move::move(core::board::point from, core::board::point to) : _from(from), _to(to)
{
}

core::board::move::move(const std::string &an) : _from(an.substr(0, 2)), _to(an.substr(2, 2))
{
}

bool core::board::move::operator==(const core::board::move &other) const
{
    return (_from == other._from) && (_to == other._to);
}

core::board::point &core::board::move::from()
{
    return _from;
}

core::board::point &core::board::move::to()
{
    return _to;
}

const core::board::point &core::board::move::from() const
{
    return _from;
}

const core::board::point &core::board::move::to() const
{
    return _to;
}

std::string core::board::move::toAN() const
{
    return _from.to_string() + _to.to_string();
}
