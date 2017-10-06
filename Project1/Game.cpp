

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

	// Get the size of the window
	CRect rect;
	//GetClientRect( &rect);
	Pen pen(Color(0, 128, 0), 3);
	graphics->DrawRectangle(&pen, (int)(rect.Width()*.2), (int)(rect.Height()*0.1), rect.Width()*0.6, rect.Height()*0.8);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}


}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CGamePiece> CGame::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}

	}

	return  nullptr;
}

/**
* Add an item to the game
* \param item New item to add
*/
void CGame::Add(std::shared_ptr<CGamePiece> item)
{
	if (item != nullptr)
	{
		mItems.push_back(item);
	}
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}


/**  Delete an item from the game
*
* \param item The item to delete.
*/
void CGame::DeleteItem(std::shared_ptr<CGamePiece> item)
{
	auto loc = find(::begin(mItems), ::end(mItems), item);
	if (loc != ::end(mItems))
	{
		mItems.erase(loc);
	}
}

/**
*  Clear the game data.
*
* Deletes all known items in the game.
*/
void CGame::Clear()
{
	mItems.clear();
}


/**  Move an item to the front of the list of items.
*
* Removes item from the list and adds it to the end so it
* will display last.
* \param item The item to move
*/
void CGame::MoveToFront(std::shared_ptr<CGamePiece> item)
{
	auto loc = find(::begin(mItems), ::end(mItems), item);
	if (loc != ::end(mItems))
	{
		mItems.erase(loc);
	}

	mItems.push_back(item);
}

CGame::CGame()
{
}


CGame::~CGame()
{
}
