#include "core/board/move.hpp"

core::board::move::move(core::board::point from, core::board::point to)
	: _from(from), _to(to) {}
	
point core::board::move::from()
{
	return _from;
}

point core::board::move::to()
{
	return _to;
}