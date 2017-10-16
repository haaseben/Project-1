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

	/**
	* Gru identifier
	* \return CMinionStuart::GruOrNot If the object is Gru
	*/
	bool CMinionJerry::GruOrNot();

private:
	///points minion is worth
	int mPoints = 1;
};

