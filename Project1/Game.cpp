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
#include "NewGame.h"
#include "GameReset.h"
#include "ScoreBoard.h"
#include "MinionJerry.h"
#include "MinionStuart.h"
#include "MinionMutant.h"


using namespace std;
using namespace Gdiplus;



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


	// From here on you are drawing virtual pixels

	AddInitialObjects();

	mScoreBoard.OnDraw(graphics,  elapsed, mGameOver);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
	mPlayingArea.OnDraw(graphics,mGameOver);
}

void CGame::AddInitialObjects()
{
	if (mVillainDrawn == 0)
	{
		/**Draw Gru
		*/
		auto Gru = make_shared<CGru>(this);
		Gru->SetLocation(-15.0, -50.0);
		mItems.push_back(Gru);
		

		/**Draw NewGame Button
		*/
		auto NewGameButton = make_shared<CNewGame>(this);
		NewGameButton->SetLocation(-740, -490.0);
		mItems.push_back(NewGameButton);

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
		if ((*i)->HitTest(x,y))
		{
			return *i;
		}
	}
	return  nullptr;
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium and if another fish is on top of it.
* \param x X location
* \param y Y location
* \param item item that is being moved and or clicked on
* \returns Pointer to item another fish is on top of.
*/
std::shared_ptr<CGamePiece> CGame::CollisionTest(int x, int y, std::shared_ptr<CGamePiece> item)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y) && *i != item)
		{
			mGameOver = true;
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
	mTotalTime += elapsed;
	bool spawn = true;
	double halfSec = 0.5;

	if ((fmod(mTotalTime, 1) < .05) && spawn == true)
	{
		SpawnMinionTimer();
		spawn = false;
	}
	if ((fmod(mTotalTime, 1) > .2) && spawn == false)
	{
		
		spawn = true;
	}

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
	double oX = (point.x - mXOffset) / mScale;
	double oY = (point.y - mYOffset) / mScale; 
	
	NewGame(oX, oY);
	mGrabbedItem = HitTest(oX,oY);
	if ( mGrabbedItem != nullptr)
	{
		// adds a duplicate to the end of the list of items
		mItems[0] = mGrabbedItem;

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
	if (mGrabbedItem != nullptr && mGrabbedItem->GruOrNot() == true)
	{
		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			//outside of left side
			if (oX <= -500.0 ) 
			{
				//top left diagnol
				if (oY <= -500.0) 
				{
					mGrabbedItem->SetLocation(-500.0 , -500.0);

				}
				//bottom left diagnol
				else if (oY >= 500 - mGrabbedItem->GetHeight())
				{
					mGrabbedItem->SetLocation(-500.0, 500.0 - mGrabbedItem->GetHeight());
				}
				//rest
				else 
				{
					mGrabbedItem->SetLocation(-500.0, oY);
				}
				
			}

			//outside of right side
			else if (oX >= 500) {
								
				//top right diagnol
				if (oY < -500)
				{
					mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), -500.0);

				}
				//bottom right diagnol
				else if (oY >= 500 - mGrabbedItem->GetHeight())
				{
					mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), 500.0 - mGrabbedItem->GetHeight());
				}

				//rest
				else
				{
						mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), oY);
				}
			
			}
			
			//outside of the top
			else if (oY <= -500.0)
			{
				//top right corner
				if (oX >= 500.0 - mGrabbedItem->GetWidth() / 2.0 &&  oX <= 500.0)
				{
					mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), -500.0);
				}
				//top left corner
				else if (oX <= -500.0 + mGrabbedItem->GetWidth() / 2.0 && oX >= -500.0)
				{
					mGrabbedItem->SetLocation(-500.0, -500.0);
				}
				
				else
				{
					mGrabbedItem->SetLocation(oX - 30.0, -500.0);

				}
			}
			
			//outside of the bottom
			else if (oY > 500.0)
			{
				//bottom right corner
				if (oX >= 500.0 - mGrabbedItem->GetWidth() / 2.0 && oX <= 500.0)
				{
					mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), 500.0 - mGrabbedItem->GetHeight());
				}
				//bottom left corner
				else if (oX <= -500.0 + mGrabbedItem->GetWidth() / 2.0 && oX >= -500.0)
				{
					mGrabbedItem->SetLocation(-500.0, 500.0 - mGrabbedItem->GetHeight());
				}

				else
				{
					mGrabbedItem->SetLocation(oX - 30.0, 500.0 - mGrabbedItem->GetHeight());

				}
				
			}
			
			else if(oX > -500.0 && oY > -500.0 && oX  < 500.0 - mGrabbedItem->GetWidth() && oY < 500.0 - mGrabbedItem->GetHeight()){
				
				mGrabbedItem->SetLocation(oX-30.0, oY-50.0);
			
			}
			
			//calls collision test to see if another fish is under the one being moved currently
			shared_ptr<CGamePiece> OtherItem = CollisionTest(oX, oY, mGrabbedItem);

			if (mGrabbedItem->GruOrNot() == true && OtherItem != nullptr)
			{
				Remove(mGrabbedItem);
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

std::shared_ptr<CGamePiece> CGame::MinionType() {
	int counter = mNumberMinions - 3;
	if (fmod(counter, 6) == 0 && counter >0)
	{
		return  make_shared<CMinionMutant>(this);
	}
	else
	{
		double minionType = ((double)rand() / RAND_MAX);
		if (minionType > .5)
		{
			return make_shared<CMinionJerry>(this);
		}
		else
		{
			return make_shared<CMinionStuart>(this);
		}
	}
}

void CGame::SpawnMinionTimer() {
	

	std::shared_ptr<CGamePiece> minion = MinionType();

	double signValue = ((double)rand() / RAND_MAX);
	if (signValue > .5)
	{
		double locX = ((double)rand() / RAND_MAX) * 480;
		minion->SetLocation(locX, -450);
	}
	else
	{
		double locX = ((double)rand() / RAND_MAX) * 500;
		minion->SetLocation(-locX, -450);
	}
	mNumberMinions += 1;
	mItems.push_back(minion);
}

void CGame::NewGame(double x, double y) 
{
	if ( (-540-200< x && x < -540) && (-380-112 <y && y < -380))
	{
		CGameReset visitor;
		mScoreBoard.Accept(&visitor);
		mItems.clear();
		mVillainDrawn = 0;
		AddInitialObjects();
		mGameOver = false;
		
		
	}

}

void CGame::Accept(CGameVisitor *visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}
