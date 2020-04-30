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
	Piezas game = Piezas();
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
	ASSERT_EQ(s10,Blank);
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
	Piezas game = Piezas();
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
	ASSERT_EQ(s10,Blank);
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
	Piezas game = Piezas();
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropLastPlace)
{
	Piezas game = Piezas();
	Piece test = game.dropPiece(3);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropTooSmall)
{
	Piezas game = Piezas();
	Piece test = game.dropPiece(-1);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, dropTooBig)
{
	Piezas game = Piezas();
	Piece test = game.dropPiece(4);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, dropFirstAndLastPlace)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	Piece test = game.dropPiece(3);
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, dropFirstAndTooBigPlace)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	Piece test = game.dropPiece(4);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, dropDouble)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, dropTriple)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	game.dropPiece(0);
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropQuadruple)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	Piece test = game.dropPiece(0);
	ASSERT_EQ(test,Blank);
}

TEST(PiezasTest, checkFirstPlace)
{
	Piezas game = Piezas();
	Piece test = game.pieceAt(0,0);
	ASSERT_EQ(test,Blank);
}
TEST(PiezasTest, checkLastPlace)
{
	Piezas game = Piezas();
	Piece test = game.pieceAt(2,3);
	ASSERT_EQ(test,Blank);
}
TEST(PiezasTest, checkTooLow)
{
	Piezas game = Piezas();
	Piece test = game.pieceAt(-1,0);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, checkTooHigh)
{
	Piezas game = Piezas();
	Piece test = game.pieceAt(3,3);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, checkTooLeft)
{
	Piezas game = Piezas();
	Piece test = game.pieceAt(0,-1);
	ASSERT_EQ(test,Invalid);
}
TEST(PiezasTest, checkTooRight)
{
	Piezas game = Piezas();
	Piece test = game.pieceAt(2,4);
	ASSERT_EQ(test,Invalid);
}

TEST(PiezasTest, dropFirstPlaceAndCheck)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	Piece test = game.pieceAt(0,0);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropLastPlaceAndCheck)
{
	Piezas game = Piezas();
	game.dropPiece(3);
	Piece test = game.pieceAt(0,3);
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, dropFirstAndLastPlaceAndCheck)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	game.dropPiece(3);
	Piece test = game.pieceAt(0,3);
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, dropFirstAndTooBigPlaceAndCheck)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	game.dropPiece(4);
	Piece test = game.pieceAt(0,3);
	ASSERT_EQ(test,Blank);
}


TEST(PiezasTest, xWins)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(3);
	Piece test = game.gameState();
	ASSERT_EQ(test,X);
}
TEST(PiezasTest, oWins)
{
	Piezas game = Piezas();
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(3);
	Piece test = game.gameState();
	ASSERT_EQ(test,O);
}
TEST(PiezasTest, invalidWins)
{
	Piezas game = Piezas();
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
	Piezas game = Piezas();
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