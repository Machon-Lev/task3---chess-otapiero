#include "Bishop.h"
#include "Board.h"
Bishop::Bishop(bool piece_color, Location& location) : ChessPiece(piece_color, location)
{
}

bool Bishop::IsLegalMove(Location& destinationLocation, Board& board)
{
	// check if the destination location is in the board limits
	if (!board.IsLegalLocation(destinationLocation))
	{
		return false;
	}

	Location currentLocation = this->GetLocation();
	// if the destination location is not on the same diagonal
	if (abs(currentLocation.x - destinationLocation.x) != abs(currentLocation.y - destinationLocation.y))
	{
		return false;
	}

	int x = currentLocation.x;
	int y = currentLocation.y;

	// check if there are any friendly pieces in the way
	while (x != destinationLocation.x || y != destinationLocation.y)
	{
		if (x != destinationLocation.x)
		{
			x += x < destinationLocation.x ? 1 : -1;
			y += y < destinationLocation.y ? 1 : -1;
		}
		
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
