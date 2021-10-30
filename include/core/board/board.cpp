#include "core/board/board.hpp"
using namespace core::board

core::win core::board::board::win()
{
	core::win winner = core::win::WHITE;
	
	return winner;
}

core::board::position core::board::board::position()
{
	core::board::position pos(core::board::pices pices, core::side::WHITE);
	
	return pos;
}

void core::board::board::apply(core::board::move move)
{
	return;
}