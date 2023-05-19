#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece
{
public:
	Queen(bool, Location&);
	bool IsLegalMove(Location&, Board&) override;


};