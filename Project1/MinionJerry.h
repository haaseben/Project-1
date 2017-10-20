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

	/// destructor
	~CMinionJerry();

	/** constructor for mutant
	* \param game
	*/
	CMinionJerry(CGame *game);

};

