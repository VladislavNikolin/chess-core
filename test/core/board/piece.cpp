#include "core/board/piece.hpp"
#include "core/board/point.hpp"
#include "core/board/side.hpp"
#include <gtest/gtest.h>

TEST(CoreBoardPieceTest, IsMyFunc)
{
    core::board::piece black_king(core::board::piece::KING, core::board::side::BLACK); 
    core::board::piece white_queen(core::board::piece::QUEEN, core::board::side::WHITE);
    
    EXPECT_EQ(black_king.is_my(core::board::side::BLACK), true);
    EXPECT_EQ(black_king.is_my(core::board::side::WHITE), false);
    EXPECT_EQ(white_queen.is_my(core::board::side::BLACK), false);
    EXPECT_EQ(white_queen.is_my(core::board::side::WHITE), true);
}

TEST(CoreBoardPieceTest, GetMovesFunc)
{
    core::board::piece black_king(core::board::piece::KING, core::board::side::BLACK); 
    core::board::point king_point {.x = 5, .y = 0};

    EXPECT_EQ(
        black_king.get_moves(king_point),
        (std::vector<core::board::move> {
            core::board::move {
                .from = king_point, 
                .to = core::board::point {.x = 4, .y = 0}
            },
            core::board::move {
                .from = king_point, 
                .to = core::board::point {.x = 6, .y = 0}
            },
            core::board::move {
                .from = king_point, 
                .to = core::board::point {.x = 4, .y = 1}
            },
            core::board::move {
                .from = king_point, 
                .to = core::board::point {.x = 5, .y = 1}
            },
            core::board::move {
                .from = king_point, 
                .to = core::board::point {.x = 6, .y = 1}
            },
        })
    );
}
