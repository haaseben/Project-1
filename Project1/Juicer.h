/**
* \file Juicer.h
*
* \author Team Jorge
*
* Class the implements Juicer
*/

#pragma once

#include <memory>

#include "GamePiece.h"
#include "Villain.h"


/**
* Implements Juicer
*/
class CJuicer : public CVillain
{
public:
	CJuicer(CGame *game);

	/// Default constructor (disabled)
	CJuicer() = delete;

	/// Copy constructor (disabled)
	CJuicer(const CJuicer &) = delete;

	virtual ~CJuicer();

	///** Accept a visitor
	//* \param visitor The visitor we accept */
	//virtual void Accept(CGameVisitor *visitor) override { visitor->VisitJuicer(this); }

	/**
	* Gru identifier
	* \return CMinionStuart::GruOrNot If the object is Gru
	*/
	bool CJuicer::GruOrNot();

	int CJuicer::GetMultiplier();



private:
	int mMultiplier = 2;
	

};