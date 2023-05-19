#include "Knight.h"
#include "Board.h"
Knight::Knight(bool piece_color, Location& location) : ChessPiece(piece_color, location)
{
}

bool Knight::IsLegalMove(Location& destinationLocation, Board& board)
{
	// check if the destination location is in the board limits
	if (!board.IsLegalLocation(destinationLocation))
	{
		return false;
	}

	Location currentLocation = this->GetLocation();
	// if the destination location is not in the L shape
	if (abs(currentLocation.x - destinationLocation.x) * abs(currentLocation.y - destinationLocation.y) != 2)
	{
		return false;
	}

	// if the destination location has a friendly piece in it return false
	if (!board.IsEmpty(destinationLocation) &&
		board.board[destinationLocation.x][destinationLocation.y]->GetColor() == this->GetColor())
	{
		return false;
	}
	// the move is legal
	return true;
}
