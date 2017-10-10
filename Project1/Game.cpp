/**
 * \file Game.cpp
 *
 * \author Team Jorge
 */



#include <memory>
#include <algorithm>
#include "stdafx.h"
#include "Game.h"
#include "Juicer.h"
#include "PokeBall.h"
#include "Arya.h"
#include "Minion.h"
#include "Gru.h"
#include "ChildView.h"
#include "ScoreBoard.h"

using namespace std;
using namespace Gdiplus;

///Base numbers for villain drawing
const int LocationX = 300;
const int LocationY = 300;

/// New game button file name
const wstring NewGameImageName = L"images/new-game.png";

/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height)
{

	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	mYOffset = height / 2.0f;

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	mPlayingArea.OnDraw(graphics);

	// From here on you are drawing virtual pixels

	double wid = mNewGameImage->GetWidth();
	double hit = mNewGameImage->GetHeight();
	graphics->DrawImage(mNewGameImage.get(),
		float(-723), float(-500),
		(float)mNewGameImage->GetWidth(), (float)mNewGameImage->GetHeight());

	AddVillain();

	mScoreBoard.OnDraw(graphics);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}

	for (auto item : mVillain)
	{
		item->Draw(graphics);
	}
	for (auto item : mGru)
	{
		item->Draw(graphics);
	}


}

void CGame::AddVillain()
{
	if (mVillainDrawn == 0)
	{
		/**Draw the Juicer
		*/
		shared_ptr<CGamePiece> juicer(new CJuicer(this));
		double juicerX = ((720) - mXOffset) / mScale;
		double juicerY = ((100) - mYOffset) / mScale;

		juicer->SetLocation(juicerX, juicerY);
		//juicer->SetLocation(LocationX*-1 + 50, LocationY*-1 - 160);
		mVillain.push_back(juicer);

		/**Draw the PokeBall
		*/
		auto pokeball = make_shared<CPokeBall>(this);
		pokeball->SetLocation(LocationX - 50, LocationY*-1 + 25);
		mVillain.push_back(pokeball);

		/**Draw Arya
		*/
		auto arya = make_shared<CArya>(this);
		arya->SetLocation(LocationX * 0 - 80, LocationY - 260);
		mVillain.push_back(arya);

		/**Draw Gru
		*/
		auto Gru = make_shared<CGru>(this);
		double GruX = ((920) - mXOffset) / mScale;
		double GryY = ((250) - mYOffset) / mScale;
		Gru->SetLocation(GruX, GryY);
		mGru.push_back(Gru);
	}




	mVillainDrawn = 1;

}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CGamePiece> CGame::HitTest(int x, int y)
{
	for (auto i = mGru.rbegin(); i != mGru.rend(); i++)
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


/**
* Handle a mouse move position
* \param x X location moved on
* \param y Y location moved on
*/
void CGame::OnMouseMove(int x, int y, UINT nFlags)
{
	double mvX = (x - mXOffset) / mScale;
	double mvY = (y - mYOffset) / mScale;

	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			mGrabbedItem->SetLocation(mvX-25, mvY-170);
		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}
	}


}

/**
* Handle a click on the playing area
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnLButtonDown(int x, int y)
{
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;

	auto mGrabbedItem = HitTest(oX, oX);



}


CGame::CGame()
{
	mNewGameImage = unique_ptr<Bitmap>(Bitmap::FromFile(NewGameImageName.c_str()));
	if (mNewGameImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += NewGameImageName;
		AfxMessageBox(msg.c_str());
	}

}


CGame::~CGame()
{
}

