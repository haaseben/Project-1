/**
 * \file GameVisitor.h
 *
 * \author Team Jorge
 *
 * Tile visitor base class.
 */

#pragma once
 // Forward references to all tile types
class CScoreBoard;
class CJuicer;
class CGru;
class CNewGame;
class CPokeBall;
class CArya;
class CMinionMutant;
class CMinionJerry;
class CMinionStuart;

/** Tile visitor base class */
class CGameVisitor
{
public:
	CGameVisitor();
	virtual ~CGameVisitor();

	/** Visit a CScoreBoard object
	* \param scoreboard Scoreboard we are visiting */
	virtual void VisitSocreBoard(CScoreBoard *scoreboard) {}

	/** Visit a CScoreBoard object
	* \param juicer Juicer we are visiting */
	virtual void VisitJuicer(CJuicer *juicer) {}

	/** Visit a CGru object
	* \param gru Gru we are visiting */
	virtual void VisitGru(CGru *gru) {}

	/** Visit a CNewGame object
	* \param newgame NewGame we are visiting */
	virtual void VisitNewGame(CNewGame *newgame) {}

	/** Visit a CPokeBall object
	* \param pokeball Pokeball we are visiting */
	virtual void VisitPokeBall(CPokeBall *pokeball) {}

	/** Visit a CArya object
	* \param arya Arya we are visiting */
	virtual void VisitArya(CArya *arya) {}

	/** Visit a CMinionMutant object
	* \param mutant MinionMutant we are visiting */
	virtual void VisitMinionMutant(CMinionMutant *mutant) {}

	/** Visit a CMinionJerry object
	* \param jerry MinionJerry we are visiting */
	virtual void VisitMinionJerry(CMinionJerry *jerry) {}

	/** Visit a CMinionStuart object
	* \param stuart MinionStuart we are visiting */
	virtual void VisitMinionStuart(CMinionStuart *stuart) {}



};

