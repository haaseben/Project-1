/**
* \file Villains.h
*
* \author Team Jorge
*
*
*/
#pragma once
#include "GamePiece.h"
#include "Game.h"

/**
*Base class for the villains
*Applies to 3 villains
*Villains are on the gameboard.
*/

class CVillains : public CGamePiece
{
public: 
	/// Default Constructor (disabled)
	CVillains() = delete;

	/// Copy Constructor (disabled)
	CVillains(const CVillains &) = delete;

	virtual ~CVillains();

protected:
	CVillains(CGame * game, const std::wstring & filename);
};


