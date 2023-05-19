#include "Pawn.h"
#include "Board.h"
Pawn::Pawn(bool piece_color, Location& location) : ChessPiece(piece_color, location)
{
	firstMove = true;
}
bool Pawn::IsLegalMove(Location& destinationLocation, Board& board)
{
	// check if the destination location is in the board limits
	if (!board.IsLegalLocation(destinationLocation))
	{
		return false;
	}

	Location currentLocation = this->GetLocation();

	// if the destination location has a friendly piece in it, return false
	if (!board.IsEmpty(destinationLocation) &&
		board.board[destinationLocation.x][destinationLocation.y]->GetColor() == this->GetColor())
	{
		return false;
	}

	int direction = (this->GetColor() == true) ? 1 : -1;
	int deltaX = destinationLocation.x - currentLocation.x;
	int deltaY = destinationLocation.y - currentLocation.y;

	// Pawn can move forward by one square
	if (deltaX == direction && deltaY == 0 && board.IsEmpty(destinationLocation))
	{
		return true;
	}

	// Pawn can move forward by two squares on its first move
	if (firstMove && (deltaX == 2 * direction && deltaY == 0) && 
		board.IsEmpty(Location(currentLocation.x + direction, currentLocation.y))&& board.IsEmpty(destinationLocation))
	{
		return true;
	}

	// Pawn can capture diagonally
	if (abs(deltaX) == 1 && abs(deltaY) == 1 && !board.IsEmpty(destinationLocation) &&
		board.board[destinationLocation.x][destinationLocation.y]->GetColor() != this->GetColor())
	{
		return true;
	}

	// Invalid move for a Pawn
	return false;
}
void Pawn::MakeMove(Location& destinationLocation, Board& board)
{
	ChessPiece::MakeMove(destinationLocation, board);
	firstMove = false;

}
void Pawn::UndoMove()
{
	firstMove = true;
	ChessPiece::UndoMove();
}