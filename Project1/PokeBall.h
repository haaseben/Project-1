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

	///** Accept a visitor
	//* \param visitor The visitor we accept */
	//virtual void Accept(CGameVisitor *visitor) override { visitor->VisitPokeBall(this); }

	/**
	* Gru identifier
	* \return CMinionStuart::GruOrNot If the object is Gru
	*/
	bool CPokeBall::GruOrNot();

	int CPokeBall::GetMultiplier();

private:
	int mMultiplier = 3;
};