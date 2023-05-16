#include "ChessPiece.h"


ChessPiece::ChessPiece(bool piece_color, Location& location) 
{
	pieceColor = piece_color;
	pieceLocation = Location(location.x,location.y);
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
