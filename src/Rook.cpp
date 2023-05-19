#include "Rook.h"
#include "Board.h"
Rook::Rook(bool piece_color, Location& location) : ChessPiece(piece_color, location)
{
}




bool Rook::IsLegalMove(Location& destinationLocation, Board& board)
{
	// check if the destination location is on the same row or column and if there are any pieces in the way

	if (!board.IsLegalLocation(destinationLocation))
	{
		return false;
	}

	Location currentLocation = this->GetLocation();
	// if the destination location is not on the same row or column
	if (currentLocation.x != destinationLocation.x && currentLocation.y != destinationLocation.y)
	{
		return false;
	}
	int xDirection = 0;
	int yDirection = 0;
	if (currentLocation.x != destinationLocation.x)
	{
		xDirection = currentLocation.x < destinationLocation.x ? 1 : -1;
	}
	else if (currentLocation.y != destinationLocation.y)
	{
		yDirection = currentLocation.y < destinationLocation.y ? 1 : -1;
	}
	currentLocation.x += xDirection;
	currentLocation.y += yDirection;
	// check if there are any friendly pieces in the way
	while (currentLocation != destinationLocation)
	{
		if (!board.IsEmpty(currentLocation))
		{
			return false;
		}
		currentLocation.x += xDirection;
		currentLocation.y += yDirection;
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
