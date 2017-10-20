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
#include "Vector.h"

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

	mScoreBoard.OnDraw(graphics, elapsed, mGameOver);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
	if (!mGameOver)
	{
		mGru->Draw(graphics);
	}

	mPlayingArea.OnDraw(graphics, mGameOver);
}
/**
* \brief adds initial objects, gru, and villians
*/
void CGame::AddInitialObjects()
{
	if (mVillainDrawn == 0)
	{
		/**Draw Gru
		*/
		auto Gru = make_shared<CGru>(this);
		Gru->SetLocation(-15.0, -50.0);
		mGru = Gru;
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
		arya->SetLocation(-50.0, 225.0);
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

		if ((mGru)->HitTest(x, y))
		{
			return mGru;
		}
		else if ((*i)->HitTest(x, y) )
		{
			return *i;
		}
		else
		{
			return nullptr;
		}
	}
	return nullptr;
}
/** Test an x,y click location to see if it clicked
* on some item in the game.
* \param x X location
* \param y Y location
* \param item item that is being moved and or clicked on
* \returns Pointer to item.
*/
std::shared_ptr<CGamePiece> CGame::CollisionTest(int x, int y, std::shared_ptr<CGamePiece> item)
{
		for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
		{
			if ((*i)->HitTest(x - 50, y - 70) && *i != item)
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
	//mGru->Update(elapsed);

	int sizeOfItems = mItems.size();
	for (auto item : mItems)
	{
		item->Update(elapsed);
		Destroy(item, item->GetX(), item->GetY());
		if (mItems.size() < sizeOfItems)
		{
			break;
		}
	}

	double x = 0;
	if (mGrabbedItem != nullptr) {
		double x = mGrabbedItem->GetX();
	}


	/// Flocking Stuff//////////////////////////////////////////////////////
	//
	Flocking();
	int counter = 0;
	
	int count2 = counter;
	


}

/**
* \brief handles the flocking of minions
*/
void CGame::Flocking()
{
	if (!mGameOver) {
		CVector cohesionCenter = CohesionCenter();

		for (auto item : mItems)
		{
			if (item->CanCollide() == true)
			{
				int itemx = item->GetX(); int itemy = item->GetY();
				if (mGru!= nullptr && mGru->HitTest(itemx, itemy) ){
					Remove(mGru);
					mGameOver = true;
				}


				CVector minionVector = item->GetPVector();
				////////////////////////////////////////////
				cv = cohesionCenter - minionVector;
				double l = cv.Length();
				if (l > 0)
				{
					cv /= l;
				}
				/////////////////////////////////////////////

				///Seperation Vector

				sv = Seperation(item);

				///Alignment
				double x = 0;
				double y = 0;
				av = Alignment(item);
				if (mGru == nullptr)
				{
					x = 0;
					y = 0;
				}
				else
				{
					x = mGru->GetX();
					y = mGru->GetY();
				}


				/// gruv vector
				//double test = &mGru->GetX();
				gruV = CVector(x, y);
				gruV = gruV - minionVector;
				if (gruV.Length() > 0)
				{
					gruV.Normalize();
				}

				CVector mV = cv * 1 + sv * 3 + av * 5 + gruV * 10;
				mV.Normalize();
				mV = mV * (item->GetBaseSpeed());
				item->SetVelocity(mV);
				////		///SET THE MINIONVECTOR SPEED VECTOR TO mv


			}

		}

		CVector mV = CVector(0, 0);
		//return mV;
	}
}
/**
* \brief alligns minions properly
* \param minion minion we're using
*\returns vector to minion
*/
CVector CGame::Alignment(std::shared_ptr<CGamePiece> minion)
{
	int alignmentCount = 0;
	CVector minionVector = minion->GetPVector();
	CVector alignmentAverage=CVector(0,0);

	for (auto item : mItems)
	{
		if (item->CanCollide() == true)
		{
			CVector testMinion = item->GetPVector();
			double testDistance = minionVector.Distance(testMinion);
			if (testDistance < 200)
			{
				alignmentCount += 1;
				alignmentAverage = alignmentAverage + item->GetVelocity();
			}
		}
	}
	av = alignmentAverage / alignmentCount;
	av = av.Normalize();
	return av;

	
}
/**
* \brief keeps minions separated
*/
CVector CGame::Seperation(std::shared_ptr<CGamePiece> minion)
{
	
	CVector closestMinionVector;
	CVector minionVector = minion->GetPVector();
	double distance = 10000;
	for (auto item : mItems)
	{
		if (item->CanCollide() == true)
		{
			if (item != minion)
			{
				CVector testMinion = item->GetPVector();
				double testDistance = minionVector.Distance(testMinion);
				if (testDistance < distance)
				{
					closestMinionVector = item->GetPVector();
					distance = testDistance;
				}
				
			}
		}
	}

	sv = minionVector - closestMinionVector;
	sv.Normalize();
	return sv;

}

/**
* \brief helps with flocking
*/
CVector CGame::CohesionCenter()
{
	CVector cohesionCenter=CVector(0,0);
	int numMinions = 0;

	for (auto item : mItems)
	{
		if (item->CanCollide() == true)
		{
			numMinions += 1;
			CVector minionVector = item->GetPVector();
			cohesionCenter = cohesionCenter + minionVector;
		}
	}

	cohesionCenter = cohesionCenter / numMinions;
	return cohesionCenter;
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
	mGrabbedItem = HitTest(oX-35, oY-75);
	if (mGrabbedItem != nullptr)
	{
		// adds a duplicate to the end of the list of items
		mGrabbedItem = mGru;

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
	if (mGrabbedItem == mGru)
	{

		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			//outside of left side
			if (oX <= -500.0 +30)
			{
				//top left diagnol
				if (oY <= -500.0+50)
				{
					mGrabbedItem->SetLocation(-500.0, -500.0 );

				}
				//bottom left diagnal
				else if (oY >= 500 -100)
				{
					mGrabbedItem->SetLocation(-500.0, 500.0 - mGrabbedItem->GetHeight());
				}
				//rest
				else
				{
					mGrabbedItem->SetLocation(-500.0, oY-45);
				}

			}

			//outside of right side
			else if (oX >= 500 -40) {

				//top right diagnal
				if (oY < -500 +50 )
				{
					mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), -500.0);

				}
				//bottom right diagnal
				else if (oY >= 500 - 100)
				{
					mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), 500.0 - mGrabbedItem->GetHeight());
				}

				//rest
				else
				{
					mGrabbedItem->SetLocation(500.0 - mGrabbedItem->GetWidth(), oY - 45);
				}

			}

			//outside of the top
			else if (oY <= -500.0 + 50)
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
			else if (oY > 500.0 -100 )
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

			else if (oX > -500.0 && oY > -500.0 && oX  < 500.0  && oY < 500.0 ) {

				mGrabbedItem->SetLocation(oX - 30.0, oY - 50.0);

			}

			//calls collision test to see if Gru has been killed
			shared_ptr<CGamePiece> OtherItem = CollisionTest(oX, oY, mGrabbedItem);

			if (mGrabbedItem == mGru)
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
	}
}

/**
* \brief assigns minion based on speed
*/
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

/**
* \brief timer for minions to spawn
*/
void CGame::SpawnMinionTimer() {

	std::shared_ptr<CGamePiece> minion = MinionType();

	double signValue = ((double)rand() / RAND_MAX);
	double locX = ((double)rand() / RAND_MAX) * 460;
	double locX2 = ((double)rand() / RAND_MAX) *-460;
	if (signValue > 0 && signValue < .5)
	{
		minion->SetLocation(locX, -450);
	}
	else
	{
		minion->SetLocation(locX2, -450);
	}
	mNumberMinions += 1;
	mItems.push_back(minion);
}

/**
* \brief creates new game 
* \param x value used to create new game
* \param y value used to create new game
*/
void CGame::NewGame(double x, double y)
{
	if ((-540 - 200< x && x < -540) && (-380 - 112 <y && y < -380))
	{
		CGameReset visitor;
		mScoreBoard.Accept(&visitor);
		mItems.clear();
		mVillainDrawn = 0;
		AddInitialObjects();
		mGameOver = false;
	}

}

/**
* Accept visitor
* \param visitor used to check type
*/
void CGame::Accept(CGameVisitor *visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}

/**
* if minion hits villian gets destroyed
* \param item item that is eating
* \param x, x is the x position of the piece that is moving
* \param y, x is the y position of the piec that is moving
*/
void CGame::Destroy(std::shared_ptr<CGamePiece> item, int x, int y) {

	for (auto i = mItems.begin(); i != mItems.end(); i++)
	{
		if ((*i)->HitTest(x - ((*i)->GetWidth() / 2), y - 30) && (*i) != item && !(*i)->CanCollide() && !mGameOver)
		{
			DeleteItem(item);
			break;
		}
	}

}