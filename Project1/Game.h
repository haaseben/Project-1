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

class CGame
{

public:
	/// cosntructor
	CGame();

	/// destructor
	virtual ~CGame();

	/**
	* OnDraw
	* \param graphics what we use to draw
	* \param width width
	* \param height height
	*/
	void OnDraw(Gdiplus::Graphics * graphics,int width,int height, double elapsed);


	void SetTimer(double elapsed);


	/**
	* add
	* \param item item we're using
	*/
	void CGame::Add(std::shared_ptr<CGamePiece> item);

	/// hittest see if item moves
	std::shared_ptr<CGamePiece> CGame::HitTest(int x, int y);

	/// update drawing
	void CGame::Update(double elapsed);

	void DeleteItem(std::shared_ptr<CGamePiece> item);

	/// clear items
	void Clear();

	/// adds a villian
	void CGame::AddVillain();

	void Remove(std::shared_ptr<CGamePiece> item); ///< remove an item from the aquarium 

	int GetXOffset() { return mXOffset; }
	int GetYOffset() { return mYOffset; }
	double GetScale() { return mScale; }

	///// Get the width of the gaming area
	///// \returns gaming area width
	//int GetWidth() const { return mBackground->GetWidth(); }

	///// Get the height of the 


	///// \returns gaming area height
	//int GetHeight() const { return mBackground->GetHeight(); }

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

	/// Any item we are currently dragging
	std::shared_ptr<CGamePiece> mGrabbedItem; 

	/// All of the items to populate in game
	std::vector<std::shared_ptr<CGamePiece> > mItems;

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

	/// An object that describes the scorebaord
	CScoreBoard mScoreBoard;



};

