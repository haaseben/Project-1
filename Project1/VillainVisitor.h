/**
* \file Villain.h
*
* \author Team Jorge
*
* Class to visit villain objects.
*/
#pragma once
#include "GameVisitor.h"

/**
* The class handles villain visits.
*/
class CVillainVisitor :
	public CGameVisitor
{
public:
	/// Consructor
	CVillainVisitor();

	/// Destructor
	~CVillainVisitor();

	/**  visits the villians 
	*\param villain the villian we are visiting
	* \return the villian */
	virtual int VisitVillain(CVillain *villain) override;

	/**  gets the score of the juicer
	* \return juicerscore */
	int CVillainVisitor::GetJuicerScore() { return mJuicerScore; }
	
	/**  gets the score of the pokeball
	* \return pokeball score */
	int CVillainVisitor::GetPokeScore() { return mPokeScore; }


	/**  gets the score of the arya
	* \return arya score */
	int CVillainVisitor::GetAryaScore() { return mAryaScroe; }

private:
	/// Collected score Juicer
	int mJuicerScore = 0;

	/// Collected socre Pokeball
	int mPokeScore = 0;

	/// Collected socre Arya
	int mAryaScroe = 0;

};

