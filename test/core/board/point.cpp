#include "core/board/point.hpp"
#include <gtest/gtest.h>

TEST(CoreBoardPointTest, ToStringFunc)
{
	core::board::point point(5, 2);
	EXPECT_EQ(point.to_string(), "e2");
}
