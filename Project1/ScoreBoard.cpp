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



/// Draw the socreboard
void CScoreBoard::OnDraw(Gdiplus::Graphics * graphics, double elapsed, bool gameover)
{
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
}



