#pragma once
#include "Location.h"
class Board;
class ChessPiece
{
	   bool pieceColor;
	   Location pieceLocation;
	
	protected:
		// return static array of array of integers that represent the directions that the piece can move
		virtual const int(*GetMoveTemplates(int index))[2]=0;
		static const int MOVE_TEMPLATES[4][2];


	public:
		ChessPiece(bool, Location&);

        virtual ~ChessPiece() = default;
		bool GetColor();
		virtual bool IsLegalMove(Location&, Board&)=0;
		virtual void MakeMove(Location&, Board&)=0;
		void SetLocation(Location&);
		Location GetLocation();

		

};