/**
 * \file ScoreBoard.cpp
 *
 * \author Team Jorge
 * Implements presentation of scoreboard
 */

#include <memory>
#include <algorithm>
#include "stdafx.h"
#include "ScoreBoard.h"
#include <string>
#include <sstream>
#include "GamePiece.h"
#include "VillainVisitor.h"
#include "Juicer.h"

using namespace std;
using namespace Gdiplus;

/// Minion filename 
const wstring AryaImageName = L"images/arya.png";

/// Minion filename 
const wstring JuicerImageName = L"images/juicer.png";

/// Minion filename 
const wstring PokeballImageName = L"images/pokeball.png";


/**
 * Constructor, draws images
 */
CScoreBoard::CScoreBoard()
{
	mJuicerImage = unique_ptr<Bitmap>(Bitmap::FromFile(JuicerImageName.c_str()));
	if (mJuicerImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += JuicerImageName;
		AfxMessageBox(msg.c_str());
	}

	mPokeballImage = unique_ptr<Bitmap>(Bitmap::FromFile(PokeballImageName.c_str()));
	if (mPokeballImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PokeballImageName;
		AfxMessageBox(msg.c_str());
	}

	mAryaImage = unique_ptr<Bitmap>(Bitmap::FromFile(AryaImageName.c_str()));
	if (mAryaImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += AryaImageName;
		AfxMessageBox(msg.c_str());
	}
	

}


/**
 * destructor
 */
CScoreBoard::~CScoreBoard()
{
}



/**
 * draws timer and counter
 * \param graphics 
 * \param elapsed 
 * \param gameover 
 */
void CScoreBoard::OnDraw(Gdiplus::Graphics * graphics, double elapsed, bool gameover)
{


	if (!gameover)
	{
		mTotalTime += elapsed;
	}


	int seconds = (int)mTotalTime % 60;
	int minutes = (int)mTotalTime / 60;
	wstring secondsString = to_wstring(seconds);
	if (seconds < 10) 
	{
		secondsString = to_wstring(0) + secondsString;
	}
	wstring fullTimeFormat = to_wstring(minutes) + L":" + secondsString;

	const wchar_t* counter = fullTimeFormat.c_str();
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 30);
	SolidBrush green(Color(0, 255, 0));
	
	graphics->DrawString(counter,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(534, -500),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with

	Gdiplus::Font fontScore(&fontFamily, 15);


	if (mJuicerScore != 0)
	{
		int widJ = mJuicerImage->GetWidth();
		int hitJ = mJuicerImage->GetHeight();
		graphics->DrawImage(mJuicerImage.get(), 550, -400, widJ, hitJ);

		graphics->DrawString((to_wstring(mJuicerScore).c_str()),  // String to draw
			-1,         // String length, -1 means it figures it out on its own
			&fontScore,      // The font to use
			PointF(590, -240),   // Where to draw (top left corner)
			&green);    // The brush to draw the text with
	}

	if (mPokeBallScore != 0)
	{
		int widP = mPokeballImage->GetWidth();
		int hitP = mPokeballImage->GetHeight();
		graphics->DrawImage(mPokeballImage.get(), 575, -180, widP, hitP);

		graphics->DrawString((to_wstring(mPokeBallScore).c_str()),  // String to draw
			-1,         // String length, -1 means it figures it out on its own
			&fontScore,      // The font to use
			PointF(590, -125),   // Where to draw (top left corner)
			&green);    // The brush to draw the text with
	}

	if (mAryaScore != 0)
	{
		int widA = mAryaImage->GetWidth();
		int hitA = mAryaImage->GetHeight();
		graphics->DrawImage(mAryaImage.get(), 534, -50, widA, hitA);

		graphics->DrawString((to_wstring(mAryaScore).c_str()),  // String to draw
			-1,         // String length, -1 means it figures it out on its own
			&fontScore,      // The font to use
			PointF(590, 110),   // Where to draw (top left corner)
			&green);    // The brush to draw the text with
	}

	if (mInitialStatus == 1 && !gameover) 
	{
		mTotalTime = 0;
		mJuicerScore = 0;
		mPokeBallScore = 0;
		mAryaScore = 0;
		mInitialStatus = 0;
	}

}

/**
 * sets jucier score
 * \param score 
 */
void CScoreBoard::SetJuicerSocre(int score)
{
	mJuicerScore += score*2;
}
/**
* sets pokeball score
* \param score
*/
void CScoreBoard::SetPokeScore(int score)
{
	mPokeBallScore += score*3;
}
/**
* sets arya score
* \param score
*/
void CScoreBoard::SetAryaScore(int score)
{
	mAryaScore += score;
}

