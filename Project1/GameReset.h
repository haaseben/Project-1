/**
 * \file GameReset.h
 *
 * \author Team Jorge
 *
 * Reset the game visitor
 */

#pragma once
#include "GameVisitor.h"

class CGameReset :
	public CGameVisitor
{
public:
	CGameReset();
	virtual ~CGameReset();

	/** Visit a CScoreBoard object
	* \param minion Minion we are visiting */
	virtual void CGameReset::VisitSocreBoard(CScoreBoard *scoreboard) override;

};

