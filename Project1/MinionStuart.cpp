/**
 * \file MinionStuart.cpp
 *
 * \author Team Jorge
 * Class that implements stuart minion.
 */

#include "stdafx.h"
#include "MinionStuart.h"


/// Minion filename 
const wstring MinionStuartImageName = L"images/stuart.png";

/**
* Constructor
* \param game Game this gamepiece is a member of
*/
CMinionStuart::CMinionStuart(CGame *game) :
	CMinion(game, MinionStuartImageName)
{
	mV = CVector(100,100);
	mBaseSpeed = 100;
	mPoints = 1;
}

/** destructor
*/
CMinionStuart::~CMinionStuart()
{
}

