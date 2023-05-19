#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
	King(bool, Location&);

	bool IsLegalMove(Location&, Board&) override;

};