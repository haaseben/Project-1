/**
* \file Gru
*
* \author Team Jorge
*
* Class the implements Gru.
*/

#pragma once

#include <memory>
#include "GamePiece.h"


/**
* Implements Gru.
*/
class CGru : public CGamePiece
{
public:
	CGru(CGame *game);

	/// Default constructor (disabled)
	CGru() = delete;

	/// Copy constructor (disabled)
	CGru(const CGru &) = delete;

	virtual ~CGru();
};