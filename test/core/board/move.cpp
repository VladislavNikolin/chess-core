#include "core/board/move.hpp"
#include <gtest/gtest.h>

TEST(CoreBoardMoveTest, ToANFunc)
{
	core::board::move move(
		core::board::point(5, 2),
		core::board::point(5, 4)
	);

	EXPECT_EQ(move.toAN(), "e2e4");
}
