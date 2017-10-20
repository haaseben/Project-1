/**
* \file MinionMutant.h
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

	/** destrutor for mutant
	*/
	~CMinionMutant();

	/** constructor for mutant
	* \param game 
	*/
	CMinionMutant(CGame *game);


};

