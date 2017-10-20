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
 * Gamereset, resets the game
 */
class CGameReset :
	public CGameVisitor
{
public:

	/// constructor
	CGameReset();

	///destructor
	virtual ~CGameReset();

	/** Visit a CScoreBoard object
	* \param scoreboard ScoreBoard we are visiting */
	virtual void CGameReset::VisitSocreBoard(CScoreBoard *scoreboard) override;

};

