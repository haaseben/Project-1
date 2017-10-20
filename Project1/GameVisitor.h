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
class CVillain;
class CMinion;

/** Tile visitor base class */
class CGameVisitor
{
public:
	CGameVisitor();
	virtual ~CGameVisitor();

	/** Visit a CScoreBoard object
	* \param scoreboard Scoreboard we are visiting */
	virtual void VisitSocreBoard(CScoreBoard *scoreboard) {}

	///** Visit a CScoreBoard object
	//* \param juicer Juicer we are visiting */
	//virtual void VisitJuicer(CJuicer *juicer) {}

	/** Visit a CGru object
	* \param gru Gru we are visiting */
	virtual void VisitGru(CGru *gru) {}

	/** Visit a CNewGame object
	* \param newgame NewGame we are visiting */
	virtual void VisitNewGame(CNewGame *newgame) {}

\
	//virtual void VisitPokeBall(CPokeBall *pokeball) {}

\
	//virtual void VisitArya(CArya *arya) {}
\
	//virtual void VisitMinionMutant(CMinionMutant *mutant) {}
\
	//virtual void VisitMinionJerry(CMinionJerry *jerry) {}

\
	//virtual void VisitMinionStuart(CMinionStuart *stuart) {}

	/** Visit a CNewGame object
	* \param villain NewGame we are visiting */
	virtual int VisitVillain(CVillain *villain) { return 1; }

	/** Visit a CNewGame object
	* \param newgame NewGame we are visiting */
	virtual int VisitMinion(CMinion *minion) { return 1; }
};

