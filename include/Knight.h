#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
private:
public:
	Knight(bool, Location&);
	bool IsLegalMove(Location&, Board&) override;

};