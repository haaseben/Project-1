/**
 * \file MinionMutant.cpp
 *
 * \author Team Jorge
 * Class that implements mutant minion.
 */

#include "stdafx.h"
#include "MinionMutant.h"


/// Minion filename 
const wstring MinionMutantImageName = L"images/mutant.png";

/**
* Constructor
* \param game Game this gamepiece is a member of
*/
CMinionMutant::CMinionMutant(CGame *game) :
	CMinion(game, MinionMutantImageName)
{
	mV = CVector(200, 200);
	mBaseSpeed = 200;
	mPoints = 5;
}

/** destructor
*/
CMinionMutant::~CMinionMutant()
{
}


