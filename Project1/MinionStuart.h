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


	//virtual void Accept(CGameVisitor *visitor) override { visitor->VisitMinionStuart(this); }

	/**
	* Gru identifier
	* \return CMinionStuart::GruOrNot If the object is Gru
	*/
	bool CMinionStuart::GruOrNot();


private:

};

