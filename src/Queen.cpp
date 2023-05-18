#include "Queen.h"
#include "Board.h"
Queen::Queen(bool piece_color, Location& location) : ChessPiece(piece_color, location)
{
}

bool Queen::IsLegalMove(Location& destinationLocation, Board& board)
{
	// check if the destination location is in the board limits
	if (!board.IsLegalLocation(destinationLocation))
	{
		return false;
	}

	Location currentLocation = this->GetLocation();
	// if the destination location is not on the same diagonal or row or column
	int x = currentLocation.x;
	int y = currentLocation.y;
	if (abs(x - destinationLocation.x) != abs(y - destinationLocation.y) && 
		(currentLocation.x != destinationLocation.x && currentLocation.y != destinationLocation.y))
	{
		return false;
	}
	int xDirection = 0;
	int yDirection = 0;
	if (x != destinationLocation.x)
	{
		xDirection = x < destinationLocation.x ? 1 : -1;
	}
	if (y != destinationLocation.y)
	{
		yDirection = y < destinationLocation.y ? 1 : -1;
	}
	// check if there are any friendly pieces in the way
	while (x != destinationLocation.x || y != destinationLocation.y)
	{
		x += xDirection;
		y += yDirection;
		if (board.IsEmpty(Location(x, y)))
		{
			continue;
		}
		if (board.board[x][y]->GetColor() == this->GetColor())
		{
			return false;
		}
	}
	// the move is legal
	return true;
}


