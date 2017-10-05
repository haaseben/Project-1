#pragma once
#include <memory>
#include <vector>
#include "GamePiece.h"

class CGame
{

public:
	CGame();

	virtual ~CGame();

	void OnDraw(Gdiplus::Graphics * graphics);

	void CGame::Add(std::shared_ptr<CGamePiece> item);

	std::shared_ptr<CGamePiece> CGame::HitTest(int x, int y);

	void CGame::Update(double elapsed);

	/// Get the width of the gaming area
	/// \returns gaming area width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns gaming area height
	int GetHeight() const { return mBackground->GetHeight(); }


private:

	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image
	/// All of the items to populate in game
	std::vector<std::shared_ptr<CGamePiece> > mItems;
};

