#pragma once
#include "Location.h"
class Board;
class ChessPiece
{
	   bool pieceColor;
	   Location pieceLocation;
	

	public:
		ChessPiece(bool, Location&);

        virtual ~ChessPiece() = default;
		bool GetColor();
		virtual bool IsLegalMove(Location&, Board&)=0;
		virtual void MakeMove(Location&, Board&);
		void SetLocation(Location&);
		Location GetLocation();

		

};