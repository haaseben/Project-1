/**
 * \file ScoreBoard.h
 *
 * \author Team jorge
 *
 * File that implements a ScoreBoard Class
 *
 */

#pragma once
#include "GameVisitor.h"
#include <memory>
 /**
 * The class that handling the score counting and image drawing. 
 */
class CScoreBoard 
{
public:
	///  Default constructor
	CScoreBoard();

	///  Copy constructor disabled
	CScoreBoard(const CScoreBoard &) = delete;

	/** Draw the socreboard
	*\param graphics graphics object
	*\param elapsed elapsed time
	*\param gameover tells if game is over
	*/
	void CScoreBoard::OnDraw(Gdiplus::Graphics * graphics, double elapsed, bool gameover);

	/// destructor
	virtual ~CScoreBoard();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CGameVisitor *visitor) { visitor->VisitSocreBoard(this); }
	
	/**  sets up the intial status
	*/
	void Initializer() { mInitialStatus = 1; }


	/// Get aryas score for test
	/// \return mAryaScore
	int GetAryaScore() { return mAryaScore; }


	void SetJuicerSocre(int socre);
	void SetPokeScore(int socre);
	void SetAryaScore(int score);
	

private:

	int mJuicerScore = 0; ///< Score for Juicer

	int mPokeBallScore = 0; ///< Score for PokeBall

	int mAryaScore = 0; ///< Score for Arya

	double mTotalTime = 0; ///< Count the total time passed

	bool mInitialStatus = 0;

	/// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mJuicerImage;

	/// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mPokeballImage;

	/// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mAryaImage;
};

