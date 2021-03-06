/**
 * \file MinionJerry.cpp
 *
 * \author Team Jorge
 * Class that implements jerry minion.
 */

#include "stdafx.h"
#include "MinionJerry.h"


/// Minion filename 
const wstring MinionJerryImageName = L"images/jerry.png";

/**
* Constructor
* \param game Game this gamepiece is a member of
*/
CMinionJerry::CMinionJerry(CGame *game) :
	CMinion(game, MinionJerryImageName)
{
	mV = CVector(100,100);
	mBaseSpeed = 100;
	mPoints = 1;
}

/** destructor
*/
CMinionJerry::~CMinionJerry()
{
}


