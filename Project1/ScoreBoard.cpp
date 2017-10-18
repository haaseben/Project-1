/**
 * \file ScoreBoard.cpp
 *
 * \author Team Jorge
 */

#include <memory>
#include <algorithm>
#include "stdafx.h"
#include "ScoreBoard.h"
#include <string>
#include <sstream>
#include "GamePiece.h"
#include "Juicer.h"

using namespace std;
using namespace Gdiplus;

/// Minion filename 
const wstring AryaImageName = L"images/arya.png";

/// Minion filename 
const wstring JuicerImageName = L"images/juicer.png";

/// Minion filename 
const wstring PokeballImageName = L"images/pokeball.png";

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


CScoreBoard::~CScoreBoard()
{
}



/// Draw the socreboard
void CScoreBoard::OnDraw(Gdiplus::Graphics * graphics, double elapsed, bool gameover)
{
	int wid = mJuicerImage->GetWidth();
	int hit = mJuicerImage->GetHeight();
	graphics->DrawImage(mJuicerImage.get(), 550, -400, wid, hit);
	
	wid = mPokeballImage->GetWidth();
	hit = mPokeballImage->GetHeight();
	graphics->DrawImage(mPokeballImage.get(), 575, -180, wid, hit);
	
	wid = mAryaImage->GetWidth();
	hit = mAryaImage->GetHeight();
	graphics->DrawImage(mAryaImage.get(), 534, -50, wid, hit);

	if (!gameover)
	{
		mTotalTime += elapsed;
	}


	int seconds = (int)mTotalTime % 60;
	int minutes = mTotalTime / 60;
	wstring secondsString = to_wstring(seconds);
	if (seconds < 10) {
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
	graphics->DrawString((to_wstring(mJuicerScore).c_str()),  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&fontScore,      // The font to use
		PointF(590, -240),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with


	graphics->DrawString((to_wstring(mPokeBallScore).c_str()),  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&fontScore,      // The font to use
		PointF(590, -125),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with

	graphics->DrawString((to_wstring(mAryaScore).c_str()),  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&fontScore,      // The font to use
		PointF(590, 110),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with

	if (mInitialStatus == 1 && !gameover) 
	{
		mTotalTime = 0;
		mInitialStatus = 0;
	}

}



