/**
* \file MinionJerry.h
*
* \author: Team Jorge
*
*  class for minion Jerry
*/


#pragma once
#include "Minion.h"

/**
* implements a jerry minion
*/
class CMinionJerry :
	public CMinion
{
public:

	/// Default constructor (disabled)
	CMinionJerry() = delete;

	/// Copy constructor (disabled)
	CMinionJerry(const CMinionJerry &) = delete;

	~CMinionJerry();

	CMinionJerry(CGame *game);

	///** Accept a visitor
	//* \param visitor The visitor we accept */
	//virtual void Accept(CGameVisitor *visitor) override { visitor->VisitMinionJerry(this); }


private:

};

