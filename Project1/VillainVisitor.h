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


	/**  gets the score of the juicer
	* \return mJuicerScore*/
	int CVillainVisitor::GetJuicerScore() { return mJuicerScore; }
	
	/**  gets the score of the pokeball
	* \return mPokeScore */
	int CVillainVisitor::GetPokeScore() { return mPokeScore; }

	/**  gets the score of the arya
	* \return mAryaScroe */
	int CVillainVisitor::GetAryaScore() { return mAryaScroe; }

private:
	/// Collected score Juicer
	int mJuicerScore = 0;

	/// Collected socre Pokeball
	int mPokeScore = 0;

	/// Collected socre Arya
	int mAryaScroe = 0;

};

