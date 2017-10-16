/**
 * \file Villain.cpp
 *
 * \author Team Jorge
 */

#include "stdafx.h"
#include "Villain.h"
#include "Game.h"


//CVillain::CVillain()
//{
//}

/** Constructor
*\param game game we're using
*/
CVillain::CVillain(CGame *game, const std::wstring &filename) :
	CGamePiece(game, filename)
{

}
/** destructor
*/
CVillain::~CVillain()
{

}
