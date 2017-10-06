/**
* \file Juicer.h
*
* \author Team Jorge
*
* Class the implements Juicer
*/

#pragma once

#include <memory>

#include "GamePiece.h"
#include "Villains.h"


/**
* Implements Juicer
*/
class CJuicer : public CGamePiece
{
public:
	CJuicer(CGame *game);

	/// Default constructor (disabled)
	CJuicer() = delete;

	/// Copy constructor (disabled)
	CJuicer(const CJuicer &) = delete;

	virtual ~CJuicer();
};