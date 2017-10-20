/**
 * \file Villain.cpp
 *
 * \author Team Jorge
 * Implements abstract villain class
 */

#include "stdafx.h"
#include "Villain.h"
#include "Game.h"




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
