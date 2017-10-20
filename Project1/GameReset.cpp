#include "stdafx.h"
#include "GameReset.h"
#include "ScoreBoard.h"

/**
* constructor
*/
CGameReset::CGameReset()
{
}

/**
* destructor
*/
CGameReset::~CGameReset()
{
}

/*
*ScoreBoard Visitor
*\param scoreboard Scoreboard this visitor is visiting
*/
void CGameReset::VisitSocreBoard(CScoreBoard *scoreboard)
{
	scoreboard->Initializer();
}