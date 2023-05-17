#include "King.h"
#include "Board.h"
King::King(bool piece_color, Location& location) : ChessPiece(piece_color, location)
{
}



bool King::IsLegalMove(Location& locationDestination, Board& board)
{
	if (!board.IsLegalLocation(locationDestination))
	{
		return false;
	}
	Location currentLocation = this->GetLocation();
	int x = currentLocation.x;
	int y = currentLocation.y;
	// check if the destination location is one square away from the current location
	if (abs(x - locationDestination.x) > 1 || abs(y - locationDestination.y) > 1)
	{
		return false;
	}

	// check if there is a friendly piece at the destination location
	if (!board.IsEmpty(locationDestination))
	{
		if (board.board[locationDestination.x][locationDestination.y]->GetColor() == this->GetColor())
		{
			return false;
		}
	}
	// the move is legal
	return true;

}
