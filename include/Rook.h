#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece
{
public:
	Rook(bool, Location&);
	bool IsLegalMove(Location&, Board&) override;

};