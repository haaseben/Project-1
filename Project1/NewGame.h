/**
 * \file NewGame.h
 *
 * \author Team Jorge
 *
 * Class that handle the new game feature
 */

#pragma once

#include "GamePiece.h"
#include <memory>

class CNewGame : public CGamePiece
{

public:
	CNewGame(CGame *game);

	/// Default constructor (disabled)
	CNewGame() = delete;

	/// Copy constructor (disabled)
	CNewGame(const CNewGame &) = delete;

	virtual ~CNewGame();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CGameVisitor *visitor) override { visitor->VisitNewGame(this); }

	/**
	* Gru identifier
	* \return CMinionStuart::GruOrNot If the object is Gru
	*/
	bool CNewGame::GruOrNot();
};
