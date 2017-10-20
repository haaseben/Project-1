/**
* \file Gru.h
*
* \author Team Jorge
*
* Class the implements Gru.
*/

#pragma once

#include <memory>
#include "GamePiece.h"
#include "Vector.h"


/**
* Implements Gru.
*/
class CGru : public CGamePiece
{
public:

	/** See if we can collide this item
	* \return bool */
	bool CanCollide() { return  false; };
	CGru(CGame *game);

	/// Default constructor (disabled)
	CGru() = delete;

	/// Copy constructor (disabled)
	CGru(const CGru &) = delete;

	virtual ~CGru();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CGameVisitor *visitor) override { visitor->VisitGru(this); }


};