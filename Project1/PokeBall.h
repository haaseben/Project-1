/**
* \file PokeBall.h
*
* \author Team Jorge
*
* Class the implements the Pokeball.
*/

#pragma once

#include <memory>

#include "GamePiece.h"
#include "Villains.h"


/**
* Implements Pokeball
*/
class CPokeBall : public CGamePiece
{
public:
	CPokeBall(CGame *game);

	/// Default constructor (disabled)
	CPokeBall() = delete;

	/// Copy constructor (disabled)
	CPokeBall(const CPokeBall &) = delete;

	virtual ~CPokeBall();
};