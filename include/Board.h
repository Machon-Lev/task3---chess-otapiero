#pragma once
#include "ChessPiece.h"
#include "Location.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

#include <string>


class Board
{
public:
	static Board& getInstance(const std::string& boardOrder = "");
	int MakeMove(std::string moveCode);
	bool IsLegalLocation(Location location);
	~Board();

private:
	ChessPiece* board[8][8];

	// a pointer to the piece that will be moved
	ChessPiece* pieceToMove;
	// a pointer to the piece that will be captured
	ChessPiece* pieceToCapture;

	// a pointer to the black king
	ChessPiece* blackKing;
	// a pointer to the white king
	ChessPiece* whiteKing;
	bool colorTurn = true;


	void InitializeBoard(const std::string& pieceOrder);
	void UndoMove(std::string moveCode);
	ChessPiece* CreatePiece(char pieceCode, Location pieceLocation);

	bool IsEmpty(Location location);
	bool IsInCheck(bool isWhite);
	friend class ChessPiece;
	friend class Rook;
	friend class King;
	friend class Bishop;
	friend class Knight;
	friend class Queen;
	friend class Pawn;

	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	Board(const std::string& board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");



};