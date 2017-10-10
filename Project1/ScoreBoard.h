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

	void CScoreBoard::Timer(double elapsed);


	

private:

	const wchar_t *counter = nullptr;

	int mAryaScore=0; ///< Score for Arya

	int mJuicerScore = 0; ///< Score for Juicer

	int mPokeBallScore = 0; ///< Score for PokeBall

	double mTotalTime = 0; ///< Count the total time passed




};

