/**
 * \file GameReset.h
 *
 * \author Team Jorge
 *
 * Reset the game visitor
 */

#pragma once
#include "GameVisitor.h"

 /**
 * ScoreBoard visitor class
 */
class CGameReset :
	public CGameVisitor
{
public:
	CGameReset();
	virtual ~CGameReset();

	/** Visit a CScoreBoard object
	* \param scoreboard ScoreBoard we are visiting */
	virtual void CGameReset::VisitSocreBoard(CScoreBoard *scoreboard) override;

};

