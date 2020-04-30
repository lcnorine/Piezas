/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, clearFilled)
{
	game = Piezas();
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(0);
	game.reset();
	Piece s00 = game.pieceAt(0,0);
	Piece s01 = game.pieceAt(0,1);
	Piece s02 = game.pieceAt(0,2);
	Piece s03 = game.pieceAt(0,3);
	Piece s10 = game.pieceAt(1,0);
	Piece s11 = game.pieceAt(1,1);
	Piece s12 = game.pieceAt(1,2);
	Piece s13 = game.pieceAt(1,3);
	Piece s20 = game.pieceAt(2,0);
	Piece s21 = game.pieceAt(2,1);
	Piece s22 = game.pieceAt(2,2);
	Piece s23 = game.pieceAt(2,3);
	ASSERT_EQ(s00,Blank);
	ASSERT_EQ(s01,Blank);
	ASSERT_EQ(s02,Blank);
	ASSERT_EQ(s03,Blank);
	ASSERT_EQ(s00,Blank);
	ASSERT_EQ(s11,Blank);
	ASSERT_EQ(s12,Blank);
	ASSERT_EQ(s13,Blank);
	ASSERT_EQ(s20,Blank);
	ASSERT_EQ(s21,Blank);
	ASSERT_EQ(s22,Blank);
	ASSERT_EQ(s23,Blank);
}
TEST(PiezasTest, clearEmpty)
{
	game = Piezas();
	game.reset();
	Piece s00 = game.pieceAt(0,0);
	Piece s01 = game.pieceAt(0,1);
	Piece s02 = game.pieceAt(0,2);
	Piece s03 = game.pieceAt(0,3);
	Piece s10 = game.pieceAt(1,0);
	Piece s11 = game.pieceAt(1,1);
	Piece s12 = game.pieceAt(1,2);
	Piece s13 = game.pieceAt(1,3);
	Piece s20 = game.pieceAt(2,0);
	Piece s21 = game.pieceAt(2,1);
	Piece s22 = game.pieceAt(2,2);
	Piece s23 = game.pieceAt(2,3);
	ASSERT_EQ(s00,Blank);
	ASSERT_EQ(s01,Blank);
	ASSERT_EQ(s02,Blank);
	ASSERT_EQ(s03,Blank);
	ASSERT_EQ(s00,Blank);
	ASSERT_EQ(s11,Blank);
	ASSERT_EQ(s12,Blank);
	ASSERT_EQ(s13,Blank);
	ASSERT_EQ(s20,Blank);
	ASSERT_EQ(s21,Blank);
	ASSERT_EQ(s22,Blank);
	ASSERT_EQ(s23,Blank);
}

TEST(PiezasTest, dropFirstPlace)
{
	game = Piezas();
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropLastPlace)
{
	game = Piezas();
	Piece test = game.dropPiece(3);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropTooSmall)
{
	game = Piezas();
	Piece test = game.dropPiece(-1);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, dropTooBig)
{
	game = Piezas();
	Piece test = game.dropPiece(4);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, dropFirstAndLastPlace)
{
	game = Piezas();
	game.dropPiece(0);
	Piece test = game.dropPiece(3);
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, dropFirstAndTooBigPlace)
{
	game = Piezas();
	game.dropPiece(0);
	Piece test = game.dropPiece(4);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, dropDouble)
{
	game = Piezas();
	game.dropPiece(0);
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, dropTriple)
{
	game = Piezas();
	game.dropPiece(0);
	game.dropPiece(0);
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropQuadruple)
{
	game = Piezas();
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,Blank);
}

TEST(PiezasTest, checkFirstPlace)
{
	game = Piezas();
	Piece test = game.pieceAt(0,0);
	ASSERT_EQ(test,Blank);
}
TEST(PiezasTest, checkLastPlace)
{
	game = Piezas();
	Piece test = game.pieceAt(2,3);
	ASSERT_EQ(test,Blank);
}
TEST(PiezasTest, checkTooLow)
{
	game = Piezas();
	Piece test = game.pieceAt(-1,0);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, checkTooHigh)
{
	game = Piezas();
	Piece test = game.pieceAt(3,3);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, checkTooLeft)
{
	game = Piezas();
	Piece test = game.pieceAt(0,-1);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, checkTooRight)
{
	game = Piezas();
	Piece test = game.pieceAt(2,4);
	ASSERT_EQ(test,Invalid);
}

TEST(PiezasTest, dropFirstPlaceAndCheck)
{
	game = Piezas();
	game.dropPiece(0);
	Piece test = game.pieceAt(0,0);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropLastPlaceAndCheck)
{
	game = Piezas();
	game.dropPiece(3);
	Piece test = game.pieceAt(0,3);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropFirstAndLastPlaceAndCheck)
{
	game = Piezas();
	game.dropPiece(0);
	game.dropPiece(3);
	Piece test = game.pieceAt(0,3);
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, dropFirstAndTooBigPlaceAndCheck)
{
	game = Piezas();
	game.dropPiece(0);
	game.dropPiece(4);
	Piece test = game.pieceAt(0,3);
	ASSERT_EQ(test,Blank);
}


TEST(PiezasTest, xWins)
{
	game = Piezas();
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(3);
	Piece test = game.gameState();
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, oWins)
{
	game = Piezas();
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(0);
	Piece test = game.gameState();
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, invalidWins)
{
	game = Piezas();
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(0);
	Piece test = game.gameState();
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, tiedWins)
{
	game = Piezas();
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	Piece test = game.gameState();
	ASSERT_EQ(test,Blank);
}