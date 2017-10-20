/**
* \file MinionStuart.h
*
* \author: Team Jorge
*
*  class for minion Stuart
*/


#pragma once
#include "Minion.h"
/**
* implements a Stuart minion
*/
class CMinionStuart :
	public CMinion
{
public:
	/// Default constructor (disabled)
	CMinionStuart() = delete;

	/// Copy constructor (disabled)
	CMinionStuart(const CMinionStuart &) = delete;

	~CMinionStuart();

	CMinionStuart(CGame *game);

	///** Accept a visitor
	//* \param visitor The visitor we accept */
	//virtual void Accept(CGameVisitor *visitor) override { visitor->VisitMinionStuart(this); }



private:

};

