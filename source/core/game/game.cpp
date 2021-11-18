#include "core/game/game.hpp"

bool core::game::game::finished()
{
	return false;
}

core::game::winner core::game::game::winner()
{
	return core::game::winner::NONE;
}

void core::game::game::turn(core::board::move move)
{
	_position.apply(move);
}

const core::board::position core::game::game::position() const 
{
	return _position;
}
