#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece
{
public:
	Bishop(bool, Location&);

	bool IsLegalMove(Location&, Board&) override;
};