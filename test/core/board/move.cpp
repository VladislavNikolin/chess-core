#include "core/board/move.hpp"
#include <gtest/gtest.h>

TEST(CoreBoardMoveTest, ToANFunc)
{
	core::board::move move {
			.from = core::board::point {.x = 5, .y = 2},
			.to = core::board::point {.x = 5, .y = 4}
	};

	EXPECT_EQ(move.toAN(), "e2e4");
}
