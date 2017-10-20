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

	~CMinionMutant();

	CMinionMutant(CGame *game);


	//virtual void Accept(CGameVisitor *visitor) override { visitor->VisitMinionMutant(this); }

	/**
	* Gru identifier
	* \return CMinionStuart::GruOrNot If the object is Gru
	*/
	bool CMinionMutant::GruOrNot();


private:

};

