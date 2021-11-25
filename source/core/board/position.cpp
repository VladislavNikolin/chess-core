#include "core/board/position.hpp"

#include "range/v3/view.hpp"

void core::board::position::apply(core::board::move move)
{
	_side = !_side;
}

std::vector<core::board::move> core::board::position::moves() const
{
	auto is_my = [&](auto p)
	{ return p.second.is_my(_side); };
	auto to_moves = [&](auto p)
	{ return p.second.get_moves(_n2xy(p.first)); };
	auto is_bad_move = [&](auto m)
	{ return _is_bad_move(m); };

	return _pieces								//
		   | ranges::views::enumerate			//
		   | ranges::views::filter(is_my)		//
		   | ranges::views::transform(to_moves) //
		   | ranges::views::cache1				// hate cxx
		   | ranges::views::join				//
		   | ranges::views::filter(is_bad_move) //
		   | ranges::to<std::vector>();
};

bool core::board::position::_is_bad_move(core::board::move move) const
{
	return false;
}

core::board::point core::board::position::_n2xy(core::board::pieces::size_type n) const
{
	return core::board::point{(uint8_t)(n % 8), (uint8_t)(n / 8)};
}

core::board::pieces::size_type core::board::position::_xy2n(core::board::point xy) const
{
	return xy.y * 8 + xy.x;
}
