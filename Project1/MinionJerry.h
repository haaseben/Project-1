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

	/**
	* Gru identifier
	* \return CMinionStuart::GruOrNot If the object is Gru
	*/
	bool CMinionJerry::GruOrNot();

	int CMinionJerry::GetPoints();

private:
	///points minion is worth
	int mPoints = 1;
};

