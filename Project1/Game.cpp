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
const double LocationX = 300.0;
const double LocationY = 300.0;

/// New game button file name
const wstring NewGameImageName = L"images/new-game.png";

/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height, double elapsed)
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

	mScoreBoard.OnDraw(graphics,  elapsed);

	for (auto item : mItems)
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

		juicer->SetLocation(-250.0, -325.0);
		mItems.push_back(juicer);

		/**Draw the PokeBall
		*/
		auto pokeball = make_shared<CPokeBall>(this);
		pokeball->SetLocation(200.0, -250.0);
		mItems.push_back(pokeball);

		/**Draw Arya
		*/
		auto arya = make_shared<CArya>(this);
		arya->SetLocation(-50.0,225.0);
		mItems.push_back(arya);

		/**Draw Gru
		*/
		auto Gru = make_shared<CGru>(this);
		Gru->SetLocation(-15.0, -50.0);
		mItems.push_back(Gru);
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
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(0,0))
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

/**  Called when there is a left mouse button press
* \param nFlags Flags associated with the mouse button press
* \param point Where the button was pressed
*/
void CGame::OnLButtonDown(UINT nFlags, CPoint point)
{
	/*double oX = (point.x - mXOffset) / mScale;
	double oY = (point.y - mYOffset) / mScale; 
	*/
	mGrabbedItem = HitTest(point.x, point.y);
	if (mGrabbedItem != nullptr)
	{
		// adds a duplicate to the end of the list of items
		Add(mGrabbedItem);

		//removes the initial object in the list
		Remove(mGrabbedItem);
	}

}

/**  Called when the mouse is moved
* \param nFlags Flags associated with the mouse movement
* \param point Where the button was pressed
*/
void CGame::OnMouseMove(UINT nFlags, CPoint point)
{
	double oX = (point.x - mXOffset) / mScale;
	double oY = (point.y - mYOffset) / mScale;

	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			//outside of left side
			if (oX <= -500 ) 
			{
				//top left diagnol
				if (oY <= -500) 
				{
					mGrabbedItem->SetLocation(-500 , -500);

				}
				//bottom left diagnol
				else if (oY >= 500 - mGrabbedItem->GetHeight())
				{
					mGrabbedItem->SetLocation(-500, 500 - mGrabbedItem->GetHeight());
				}
				//rest
				else 
				{
					mGrabbedItem->SetLocation(-500, oY);
				}
				
			}

			//outside of right side
			else if (oX >= 500) {
								
				//top right diagnol
				if (oY < -500)
				{
					mGrabbedItem->SetLocation(500 - mGrabbedItem->GetWidth(), -500);

				}
				//bottom right diagnol
				else if (oY >= 500 - mGrabbedItem->GetHeight())
				{
					mGrabbedItem->SetLocation(500 - mGrabbedItem->GetWidth(), 500 - mGrabbedItem->GetHeight());
				}

				//rest
				else
				{
						mGrabbedItem->SetLocation(500 - mGrabbedItem->GetWidth(), oY);
				}
			
			}
			
			//outside of the top
			else if (oY <= -500 )
			{
				//top right corner
				if (oX >= 500 - mGrabbedItem->GetWidth() / 2 &&  oX <= 500)
				{
					mGrabbedItem->SetLocation(500 - mGrabbedItem->GetWidth(), -500);
				}
				//top left corner
				else if (oX <= -500 + mGrabbedItem->GetWidth() / 2 && oX >= -500)
				{
					mGrabbedItem->SetLocation(-500 , -500);
				}
				
				else
				{
					mGrabbedItem->SetLocation(oX - 30, -500);

				}
			}
			
			//outside of the bottom
			else if (oY > 500) 
			{
				//bottom right corner
				if (oX >= 500 - mGrabbedItem->GetWidth() / 2 && oX <= 500)
				{
					mGrabbedItem->SetLocation(500 - mGrabbedItem->GetWidth(), 500 - mGrabbedItem->GetHeight());
				}
				//bottom left corner
				else if (oX <= -500 + mGrabbedItem->GetWidth() / 2 && oX >= -500)
				{
					mGrabbedItem->SetLocation(-500, 500 - mGrabbedItem->GetHeight());
				}

				else
				{
					mGrabbedItem->SetLocation(oX - 30, 500 - mGrabbedItem->GetHeight());

				}
				
			}
			
			else if(oX > -500 && oY > -500 && oX  < 500 - mGrabbedItem->GetWidth() && oY < 500 - mGrabbedItem->GetHeight()){
				
				mGrabbedItem->SetLocation(oX-30, oY-50);
			
			} 
		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}

		// Force the screen to redraw
	}
}
void CGame::SetTimer(double elapsed) {

	mScoreBoard.Timer(elapsed);
}