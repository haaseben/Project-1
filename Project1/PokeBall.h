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
#include "Villain.h"


/**
* Implements Pokeball
*/
class CPokeBall : public CVillain
{
public:
	/// constructor
	CPokeBall(CGame *game);

	/// Default constructor (disabled)
	CPokeBall() = delete;

	/// Copy constructor (disabled)
	CPokeBall(const CPokeBall &) = delete;

	/// destructor
	virtual ~CPokeBall();
};