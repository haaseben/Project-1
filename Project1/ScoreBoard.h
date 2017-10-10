/**
 * \file ScoreBoard.h
 *
 * \author Team jorge
 *
 * File that implements a ScoreBoard Class
 *
 */

#pragma once
class CScoreBoard 
{
public:
	///  Default constructor

	CScoreBoard() ;

	///  Copy constructor disabled
	CScoreBoard(const CScoreBoard &) = delete;

	/// Draw the socreboard
	void CScoreBoard::OnDraw(Gdiplus::Graphics * graphics);

	virtual ~CScoreBoard();

private:

	int mAryaScore=0; ///< Score for Arya

	int mJuicerScore = 0; ///< Score for Juicer

	int mPokeBallScore = 0; ///< Score for PokeBall

};

