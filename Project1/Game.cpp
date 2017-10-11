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
		double juicerX = LocationX*-1 + 50;
		double juicerY = LocationY*-1 - 160;

		juicer->SetLocation(juicerX, juicerY);
		mVillain.push_back(juicer);

		/**Draw the PokeBall
		*/
		auto pokeball = make_shared<CPokeBall>(this);
		pokeball->SetLocation(LocationX-100, LocationY*-1 + 25);
		mVillain.push_back(pokeball);

		/**Draw Arya
		*/
		auto arya = make_shared<CArya>(this);
		arya->SetLocation(-80, LocationY - 260);
		mVillain.push_back(arya);

		/**Draw Gru
		*/
		auto Gru = make_shared<CGru>(this);
		double GruX = ((920) - mXOffset) / mScale;
		double GryY = ((250) - mYOffset) / mScale;
		Gru->SetLocation(-40, LocationY*-1 + 70);
		mGru.push_back(Gru);
	}


	mVillainDrawn = 1;

}

/** Test an x,y click location to see if it clicked
* on some item in the game.
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


/**
*destructor
*/
CGame::~CGame()
{
}

/**
* move items to the back of a list
* \param item item that needs to be deleted
*/
void CGame::Remove(std::shared_ptr<CGamePiece> item)
{
	auto loc = find(::begin(mItems), ::end(mItems), item);
	if (loc != ::end(mItems))
	{
		mItems.erase(loc);
	}

}