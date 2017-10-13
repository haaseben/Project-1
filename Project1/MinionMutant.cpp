/**
 * \file MinionMutant.cpp
 *
 * \author Team Jorge
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
	SetSpeedX(100);
	SetSpeedY(140);
}

/** destructor
*/
CMinionMutant::~CMinionMutant()
{
}


bool CMinionMutant::GruOrNot()
{
	return false;
}