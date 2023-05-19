#include "ChessPiece.h"
#include "Board.h"


ChessPiece::ChessPiece(bool piece_color, Location& location) 
{
	pieceColor = piece_color;
	pieceLocation = Location(location.x,location.y);
}
void ChessPiece::MakeMove(Location& destinationLocation, Board& board)
{
	if (IsLegalMove(destinationLocation, board))
	{
		board.board[destinationLocation.x][destinationLocation.y] = this;
		board.board[this->GetLocation().x][this->GetLocation().y] = nullptr;

		SetLocation(destinationLocation);
	}
}

bool ChessPiece::GetColor()
{
	return pieceColor;
}
void ChessPiece::SetLocation(Location& location)
{
	pieceLocation = Location(location.x,location.y);
}
Location ChessPiece::GetLocation()
{
	return pieceLocation;
}
