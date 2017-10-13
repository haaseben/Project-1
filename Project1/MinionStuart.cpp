/**
 * \file MinionStuart.cpp
 *
 * \author Team Jorge
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
	SetSpeedX(50);
	SetSpeedY(70);
}

/** destructor
*/
CMinionStuart::~CMinionStuart()
{
}

bool CMinionStuart::GruOrNot()
{
	return false;
}