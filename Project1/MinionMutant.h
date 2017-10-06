/**
* \file:MinionMutant.h
*
* \author: Team Jorge
*
*  class for mutant minion 
*/


#pragma once
#include "Minion.h"
/**
* implements a mutant minion
*/
class CMinionMutant :
	public CMinion
{
public:
	/// Default constructor (disabled)
	CMinionMutant() = delete;

	/// Copy constructor (disabled)
	CMinionMutant(const CMinionMutant &) = delete;

	~CMinionMutant();

	CMinionMutant(CGame *game);


private:
	///points minion is worth
	int mPoints = 5;
};

