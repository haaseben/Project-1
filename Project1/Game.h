#pragma once
#include <memory>
#include <vector>
#include "GamePiece.h"
#include "PlayingArea.h"

class CGame
{

public:
	CGame();

	virtual ~CGame();

	virtual void OnDraw(Gdiplus::Graphics * graphics,int width,int height);

	void CGame::Add(std::shared_ptr<CGamePiece> item);

	std::shared_ptr<CGamePiece> CGame::HitTest(int x, int y);

	void CGame::Update(double elapsed);

	void DeleteItem(std::shared_ptr<CGamePiece> item);

	void Clear();

	void MoveToFront(std::shared_ptr<CGamePiece> item);


	///// Get the width of the gaming area
	///// \returns gaming area width
	//int GetWidth() const { return mBackground->GetWidth(); }

	///// Get the height of the aquarium
	///// \returns gaming area height
	//int GetHeight() const { return mBackground->GetHeight(); }


private:

	//std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image
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

};

