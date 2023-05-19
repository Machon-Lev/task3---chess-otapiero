#pragma once
#include "ChessPiece.h"
class Pawn : public ChessPiece
{
	private:
	bool firstMove;
public:
	Pawn(bool, Location&);

	void MakeMove(Location&, Board&)override;
	void UndoMove()override;
	bool IsLegalMove(Location&, Board&) override;
};