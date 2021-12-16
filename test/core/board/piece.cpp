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

TEST(CoreBoardPieceTest, GetMovesFunc_King)
{
	core::board::piece white_king(core::board::piece::KING, core::board::side::WHITE);
	core::board::point king_point(5, 1);

	EXPECT_EQ(
		white_king.get_moves(king_point),
		(std::vector<core::board::move>{
			core::board::move(
				king_point,
				core::board::point(4, 1)),
			core::board::move(
				king_point,
				core::board::point(4, 2)),
			core::board::move(
				king_point,
				core::board::point(5, 2)),
			core::board::move(
				king_point,
				core::board::point(6, 1)),
			core::board::move(
				king_point,
				core::board::point(6, 2)),
			core::board::move(
				king_point,
				core::board::point(3, 1)),
			core::board::move(
				king_point,
				core::board::point(7, 1)),
		}));
}

TEST(CoreBoardPieceTest, GetMovesFunc_Knight)
{
	core::board::piece white_knight(core::board::piece::KNIGHT, core::board::side::WHITE);
	core::board::point knight_point(2, 1);

	EXPECT_EQ(
		white_knight.get_moves(knight_point),
		(std::vector<core::board::move>{
			core::board::move(
				knight_point,
				core::board::point(4, 2)),
			core::board::move(
				knight_point,
				core::board::point(3, 3)),
			core::board::move(
				knight_point,
				core::board::point(1, 3)),
		}));
}

TEST(CoreBoardPieceTest, GetMovesFunc_Pawn)
{
	core::board::piece white_pawn(core::board::piece::PAWN, core::board::side::WHITE);
	core::board::point pawn_point(3, 2);

	EXPECT_EQ(
		white_pawn.get_moves(pawn_point),
		(std::vector<core::board::move>{
			core::board::move(
				pawn_point,
				core::board::point(3, 3)),
			core::board::move(
				pawn_point,
				core::board::point(3, 4)),
			core::board::move(
				pawn_point,
				core::board::point(2, 3)),
			core::board::move(
				pawn_point,
				core::board::point(4, 3)),
		}));
}

TEST(CoreBoardPieceTest, GetMovesFunc_Bishop)
{
	core::board::piece black_bishop(core::board::piece::BISHOP, core::board::side::BLACK);
	core::board::point bishop_point(3, 8);

	EXPECT_EQ(
		black_bishop.get_moves(bishop_point),
		(std::vector<core::board::move>{
			core::board::move(
				bishop_point,
				core::board::point(4, 7)),
			core::board::move(
				bishop_point,
				core::board::point(2, 7)),
			core::board::move(
				bishop_point,
				core::board::point(5, 6)),
			core::board::move(
				bishop_point,
				core::board::point(1, 6)),
			core::board::move(
				bishop_point,
				core::board::point(6, 5)),
			core::board::move(
				bishop_point,
				core::board::point(7, 4)),
			core::board::move(
				bishop_point,
				core::board::point(8, 3)),
		}));
}

TEST(CoreBoardPieceTest, GetMovesFunc_Rook)
{
	core::board::piece black_rook(core::board::piece::ROOK, core::board::side::BLACK);
	core::board::point rook_point(1, 8);

	EXPECT_EQ(
		black_rook.get_moves(rook_point),
		(std::vector<core::board::move>{
			core::board::move(
				rook_point,
				core::board::point(2, 8)),
			core::board::move(
				rook_point,
				core::board::point(1, 7)),
			core::board::move(
				rook_point,
				core::board::point(3, 8)),
			core::board::move(
				rook_point,
				core::board::point(1, 6)),
			core::board::move(
				rook_point,
				core::board::point(4, 8)),
			core::board::move(
				rook_point,
				core::board::point(1, 5)),
			core::board::move(
				rook_point,
				core::board::point(5, 8)),
			core::board::move(
				rook_point,
				core::board::point(1, 4)),
			core::board::move(
				rook_point,
				core::board::point(6, 8)),
			core::board::move(
				rook_point,
				core::board::point(1, 3)),
			core::board::move(
				rook_point,
				core::board::point(7, 8)),
			core::board::move(
				rook_point,
				core::board::point(1, 2)),
			core::board::move(
				rook_point,
				core::board::point(8, 8)),
			core::board::move(
				rook_point,
				core::board::point(1, 1)),

		}));
}

TEST(CoreBoardPieceTest, GetMovesFunc_Queen)
{
	core::board::piece black_queen(core::board::piece::QUEEN, core::board::side::BLACK);
	core::board::point queen_point(1, 8);

	EXPECT_EQ(
		black_queen.get_moves(queen_point),
		(std::vector<core::board::move>{
			core::board::move(
				queen_point,
				core::board::point(2, 8)),
			core::board::move(
				queen_point,
				core::board::point(1, 7)),
			core::board::move(
				queen_point,
				core::board::point(3, 8)),
			core::board::move(
				queen_point,
				core::board::point(1, 6)),
			core::board::move(
				queen_point,
				core::board::point(4, 8)),
			core::board::move(
				queen_point,
				core::board::point(1, 5)),
			core::board::move(
				queen_point,
				core::board::point(5, 8)),
			core::board::move(
				queen_point,
				core::board::point(1, 4)),
			core::board::move(
				queen_point,
				core::board::point(6, 8)),
			core::board::move(
				queen_point,
				core::board::point(1, 3)),
			core::board::move(
				queen_point,
				core::board::point(7, 8)),
			core::board::move(
				queen_point,
				core::board::point(1, 2)),
			core::board::move(
				queen_point,
				core::board::point(8, 8)),
			core::board::move(
				queen_point,
				core::board::point(1, 1)),
			core::board::move(
				queen_point,
				core::board::point(2, 7)),
			core::board::move(
				queen_point,
				core::board::point(3, 6)),
			core::board::move(
				queen_point,
				core::board::point(4, 5)),
			core::board::move(
				queen_point,
				core::board::point(5, 4)),
			core::board::move(
				queen_point,
				core::board::point(6, 3)),
			core::board::move(
				queen_point,
				core::board::point(7, 2)),
			core::board::move(
				queen_point,
				core::board::point(8, 1)),
		}));
}

TEST(CoreBoardPieceTest, GetMovesFunc_None)
{
	core::board::piece none(core::board::piece::NONE, core::board::side::NONE);
	core::board::point none_point(3, 4);

	EXPECT_EQ(
		none.get_moves(none_point),
		(std::vector<core::board::move>{}));
}

TEST(CoreBoardPieceTest, OperatorAssign)
{
	core::board::piece black_rook(core::board::piece::ROOK, core::board::side::BLACK);
	core::board::piece white_queen(core::board::piece::QUEEN, core::board::side::WHITE);

	EXPECT_EQ(
		black_rook = white_queen,
		white_queen);
}

TEST(CoreBoardPieceTest, OperatorEqual)
{
	core::board::piece black_rook(core::board::piece::ROOK, core::board::side::BLACK);
	core::board::piece black_rook_2(core::board::piece::ROOK, core::board::side::BLACK);
	core::board::piece white_queen(core::board::piece::QUEEN, core::board::side::WHITE);

	EXPECT_EQ(
		black_rook == black_rook,
		true);

	EXPECT_EQ(
		black_rook == white_queen,
		false);
}

//TEST(CoreBoardPieceTest, WasMovingFunc)
//{
//	core::board::piece black_rook(core::board::piece::ROOK, core::board::side::BLACK);
//	black_rook;
//
//	EXPECT_EQ(
//		black_rook == black_rook,
//		true
//	);
//
//	EXPECT_EQ(
//		black_rook == white_queen,
//		false
//	);
//}

TEST(CoreBoardPieceTest, GetPieceTFunc)
{
	core::board::piece black_rook(core::board::piece::ROOK, core::board::side::BLACK);

	EXPECT_EQ(
		black_rook.get_piece_t(),
		core::board::piece::ROOK);
}

TEST(CoreBoardPieceTest, PieceConstructor)
{
	core::board::piece white_pawn(core::board::piece::PAWN, core::board::side::WHITE);

	EXPECT_EQ(
		core::board::piece('P'),
		white_pawn);
}
