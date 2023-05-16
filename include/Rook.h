#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece
{
private:
	const int(*GetMoveTemplates(int index))[2] override;
public:
	Rook(bool, Location&);

	void MakeMove(Location&, Board&) override;

	bool IsLegalMove(Location&, Board&) override;

};