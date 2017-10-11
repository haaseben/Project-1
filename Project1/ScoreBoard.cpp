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
}


CScoreBoard::~CScoreBoard()
{
}

void CScoreBoard::Timer(double elapsed)
{
	mTotalTime += elapsed;
	int seconds = (int)mTotalTime % 60;
	int minutes = mTotalTime / 60;
	wstring secondsString = to_wstring(seconds);
	if (seconds < 10) {
		secondsString = to_wstring(0) + secondsString;
	}
	wstring fullTimeFormat = to_wstring(minutes) + L":" + secondsString;
	counter = fullTimeFormat.c_str();

}

/// Draw the socreboard
void CScoreBoard::OnDraw(Gdiplus::Graphics * graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);
	SolidBrush green(Color(0, 255, 0));

	//graphics->DrawString(L"Arial",  // String to draw
	//	-1,         // String length, -1 means it figures it out on its own
	//	&font,      // The font to use
	//	PointF(0, 0),   // Where to draw (top left corner)
	//	&green);    // The brush to draw the text with
}



