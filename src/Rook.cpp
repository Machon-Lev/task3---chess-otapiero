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

	int x = currentLocation.x;
	int y = currentLocation.y;
	// check if there are any friendly pieces in the way
	while (x != destinationLocation.x || y != destinationLocation.y)
	{
		if (x != destinationLocation.x)
		{
			x += x < destinationLocation.x ? 1 : -1;
		}
		else if (y != destinationLocation.y)
		{
			y += y < destinationLocation.y ? 1 : -1;
		}
		if (board.IsEmpty(Location(x, y)))
		{
			continue;
		}
		if (board.board[x][y]->GetColor()==this->GetColor())
		{
			return false;
		}
	}
	// the move is legal
	return true;
}
