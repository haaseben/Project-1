#include "stdafx.h"
#include "GameReset.h"
#include "ScoreBoard.h"


CGameReset::CGameReset()
{
}


CGameReset::~CGameReset()
{
}

void CGameReset::VisitSocreBoard(CScoreBoard *scoreboard)
{
	scoreboard->Initializer();
}