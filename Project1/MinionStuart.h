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

	/** destructor for stuart
	*/
	~CMinionStuart();
	
	/** constructor for minion stuart
	* \param game
	*/
	CMinionStuart(CGame *game);

};

