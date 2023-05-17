#include "Board.h"

Board::Board(const std::string& pieceOrder)
{
	InitializeBoard(pieceOrder);
}

Board::~Board()
{
	// delete all the pieces
	for (int i = 0; i < 8; i++) {
		for (int j = 0; i < 8; i++) {
			
			delete board[i][j];
		}
	}
}

ChessPiece* Board::CreatePiece(char pieceCode, Location pieceLocation)
{
    switch (pieceCode) {
/*	case 'P':
		return new Pawn(true,pieceLocation);
	case 'N':
		return new Knight(true, pieceLocation);
	case 'B':
		return new Bishop(true, pieceLocation);*/
	case 'R':
		return new Rook(true,pieceLocation);
/*	case 'Q':
		return new Queen(true, pieceLocation);
		*/
	case 'K':
		whiteKing = new King(true, pieceLocation);
		return whiteKing;
		/*
	case 'p':
		return new Pawn(false, pieceLocation);
	case 'n':	
		return new Knight(false, pieceLocation);
	case 'b':
		return new Bishop(false, pieceLocation
		*/
	case 'r':
		return new Rook(false, pieceLocation);
		/*
	case 'q':
		return new Queen(false, pieceLocation);
		*/
	case 'k':
		blackKing = new King(false, pieceLocation);
		return blackKing;
	default:
		return nullptr;
	}
}

bool Board::IsEmpty(Location location)
{
	return board[location.x][location.y] == nullptr;

}

bool Board::IsInCheck(bool kingColor)
{
	// check if the king is in check
	// get the location of the king
	Location kingLocation = kingColor ? whiteKing->GetLocation() : blackKing->GetLocation();
	// check if any of the opponent's pieces can capture the king
	// loop through the board
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// if the piece is not null and is not the same color as the king
			if (!IsEmpty(Location(i,j)) && board[i][j]->GetColor() != kingColor)
			{
				// if the piece can capture the king
				if (board[i][j]->IsLegalMove(kingLocation, *this)) 
				{
					// the king is in check
					return true;
				}
			}
		}
	}
	// the king is not in check
	return false;
	
}

bool Board::IsLegalLocation(Location location)
{
	return location.x >= 0 && location.x < 8 && location.y >= 0 && location.y < 8;
}

Board& Board::getInstance(const std::string& boardOrder )
{
	static Board instance(boardOrder);
	return instance;
}

int Board::MakeMove(std::string moveCode)
{
	// get the location of the piece to move
	Location from = Location(moveCode[0], moveCode[1]);
	if (IsEmpty(from))
	{
		return 11;
	}
	// get the location of the piece to capture
	Location to = Location(moveCode[2], moveCode[3]);
	// get the piece to move
	pieceToMove = board[from.x][from.y];
	// get the piece to capture
	pieceToCapture = board[to.x][to.y];
	// if the piece to move is not yours
	if (pieceToMove->GetColor() != colorTurn)
	{
		return 12;
	}
	// if the piece in destination is yours
	if (!IsEmpty(to) && pieceToCapture->GetColor() == colorTurn)
	{
		return 13;
	}
	// if the move is not legal
	if (!pieceToMove->IsLegalMove(to, *this))
	{
		return 21;
	}
	// do the move
	pieceToMove->MakeMove(to, *this);
	// if your king is in check
	if (IsInCheck(colorTurn))
	{
		// undo the move
		UndoMove(moveCode);
		return 31;
	}
	// if the opponent's king is in check
	if (IsInCheck(!colorTurn))
	{
		colorTurn = !colorTurn;
		return 41;
	}

	// you made a legal move, change the turn
	colorTurn = !colorTurn;
	pieceToMove = nullptr;
	if (pieceToCapture != nullptr)
	{
		delete pieceToCapture;
	}
	pieceToCapture = nullptr;
	return 42;
}

void Board::InitializeBoard(const std::string& pieceOrder )
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = CreatePiece(pieceOrder[i * 8 + j], Location(i, j));
        }
    }
}

void Board::UndoMove(std::string moveCode)
{
	if (pieceToMove == nullptr)
	{
		return;
	}
	Location from = Location(moveCode[0], moveCode[1]);
    Location to = Location(moveCode[2], moveCode[3]);	
	if (pieceToCapture != nullptr)
	{
		pieceToCapture->SetLocation(to);
		board[pieceToCapture->GetLocation().x][pieceToCapture->GetLocation().y] = pieceToCapture;
		pieceToCapture = nullptr;
	}
	else
	{
		board[to.x][to.y] = nullptr;
	}
	board[from.x][from.y] = pieceToMove;
	pieceToMove->SetLocation(from);
}
