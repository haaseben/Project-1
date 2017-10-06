/**
* \file Arya.h
*
* \author Team Jorge
*
* Class the implements Arya.
*/

#pragma once

#include <memory>

#include "GamePiece.h"
#include "Villains.h"


/**
* Implements Arya
*/
class CArya: public CGamePiece
{
public:
	CArya(CGame *game);

	/// Default constructor (disabled)
	CArya() = delete;

	/// Copy constructor (disabled)
	CArya(const CArya &) = delete;

	virtual ~CArya();
};