/**
 * \file Game.h
 *
 * \author Team Jorge
 *
 * The main game class
 */

#pragma once
#include <memory>
#include <vector>
#include "GamePiece.h"
#include "PlayingArea.h"
#include "ScoreBoard.h"
#include "Vector.h"

 /**
 * The class that handle the game and all components in the game. 
 */
class CGame
{

public:
	/// cosntructor
	CGame();

	/// destructor
	virtual ~CGame();


	void SetVelocity(CVector NewVector) { mV = NewVector; }

	/// Velocity in virtual pixels/second
	CVector mV;

	/**
	* OnDraw
	* \param graphics What we use to draw
	* \param width Width
	* \param height Height
	* \param elapsed Elapsed tiem
	*/
	void OnDraw(Gdiplus::Graphics * graphics,int width,int height, double elapsed);

	/*Potential flocking functions.
	/ Adding all vectors.
	*/

	// Cohesion vector
	CVector cv;

	// Separation vector
	CVector sv;

	// Alignment vector
	CVector av;

	// Gru vector
	CVector gruV;


	CVector CGame::CohesionCenter();

	/**
	* Add
	* \param item item we're using
	*/
	void CGame::Add(std::shared_ptr<CGamePiece> item);

	/// hittest see if item moves
	std::shared_ptr<CGamePiece> CGame::HitTest(int x, int y);

	/// update drawing
	void CGame::Update(double elapsed);

	void DeleteItem(std::shared_ptr<CGamePiece> item);

	void Destroy(std::shared_ptr<CGamePiece> item, int x, int y);


	/// clear items
	void Clear();

	/// add game initial objects
	void CGame::AddInitialObjects();

	/// Controls minions spawning timer
	void CGame::SpawnMinionTimer();

	/// Create a new game
	void CGame::NewGame(double x, double y);
	/** Gets Minion Type
	*\return CGame::MinionType minion type
	*/
	std::shared_ptr<CGamePiece> CGame::MinionType();

	void Remove(std::shared_ptr<CGamePiece> item); ///< remove an item from the aquarium 

	std::shared_ptr<CGamePiece> CGame::CollisionTest(int x, int y, std::shared_ptr<CGamePiece> item);

	/** Accept a visitor for the collection
	* \param visitor The visitor for the collection
	*/
	void CGame::Accept(CGameVisitor *visitor);




	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);


	/** Iterator that iterates over the city tiles */
	class Iter
	{
	public:
		/** Constructor
		* \param city The city we are iterating over
		* \param pos postion
		*/
		Iter(CGame *city, int pos) : mGame(city), mPos(pos) {}

		/** Test for end of the iterator
		* \param other comparison
		* \returns True if we this position equals not equal to the other position */
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** Get value at current position
		* \returns Value at mPos in the collection */
		std::shared_ptr<CGamePiece> operator *() const { return mGame->mItems[mPos]; }

		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}






	private:
		CGame *mGame;   ///< City we are iterating over
		int mPos;       ///< Position in the collection
	};

	/** Get an iterator for the beginning of the collection
	* \returns Iter object at position 0 */
	Iter begin() { return Iter(this, 0); }

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the end */
	Iter end() { return Iter(this, mItems.size()); }


private:

	/// Minion Counter
	int mNumberMinions=0;

	/// Any item we are currently dragging
	std::shared_ptr<CGamePiece> mGrabbedItem; 

	/// All of the items to populate in game
	std::vector<std::shared_ptr<CGamePiece> > mItems;

	/// Any item we are currently dragging
	std::shared_ptr<CGamePiece> mGru;

	/// Game area width in virtual pixels
	const static int Width = 1400;

	/// Game area height in virtual pixels
	const static int Height = 1100;

	/// Scale value
	float mScale = 0;

	/// Variable of XOffset
	double mXOffset = 0;

	/// Variable of YOffset
	double mYOffset = 0;

	/// An object that describes the playing area
	CPlayingArea  mPlayingArea;

	/// New Game Image
	std::unique_ptr<Gdiplus::Bitmap> mNewGameImage;

	/// If villains has been drawn for the new game. 
	bool mVillainDrawn = 0;

	double mTotalTime = 0; ///< Count the total time passed

	/// An object that describes the scorebaord
	CScoreBoard mScoreBoard;

	/// If the game is over
	bool mGameOver = false;

	/*Potential flocking functions.
	/ Adding all vectors.
	*/

	// Cohesion vector
	CVector cv;

	// Separation vector
	CVector sv;

	// Alignment vector
	CVector av;

	// Gru vector
	CVector gruV;
};