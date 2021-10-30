#include "position.hpp"

core::board::position::position(core::board::pieces pieces, core::side side)
	: _pieces(pieces), _side(side){}

core::side core::board::position::side();
{
	return _side;
}

std::vector<core::board::point> pieces()
{
	std::vector<core::board::move> _pieces;
	
	return _pieces;
}

std::vector<core::board::move> moves(core::board::point from)
{
	std::vector<core::board::move> _moves;
	
	return _moves;
}