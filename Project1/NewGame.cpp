/**
 * \file NewGame.cpp
 *
 * \author Team Jorge
 */

#include "stdafx.h"
#include <string>
#include "NewGame.h"
#include "Game.h"

using namespace std;

 /// Gru filename
const wstring NewGameImageName = L"images/new-game.png";

/** Constructor
* \param game The game this is a member of
*/
CNewGame::CNewGame(CGame *game) :
	CGamePiece(game, NewGameImageName)
{

}

CNewGame::~CNewGame()
{

}

bool CNewGame::GruOrNot()
{
	return false;
}