

#include <memory>
#include <algorithm>
#include "stdafx.h"
#include "Game.h"
#include "Minion.h"

using namespace std;
using namespace Gdiplus;

/** Draw the game
* \param graphics The GDI+ graphics context to draw on
*/
void CGame::OnDraw(Gdiplus::Graphics *graphics)
{
	//graphics->DrawImage(mBackground.get(), 0, 0,
	//	mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}


}


CGame::CGame()
{
}


CGame::~CGame()
{
}
