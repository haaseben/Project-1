/**
 * \file MinionJerry.cpp
 *
 * \author Team Jorge
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
	
}

/** destructor
*/
CMinionJerry::~CMinionJerry()
{
}


bool CMinionJerry::GruOrNot()
{
	return false;
}

int CMinionJerry::GetPoints()
{
	return mPoints;
}