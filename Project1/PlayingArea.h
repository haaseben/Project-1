#pragma once

class CPlayingArea
{
public:

	const static double GridSize;
	const static double GridRadius;
	const static double GridMargin;

	CPlayingArea();
	~CPlayingArea();

	void OnDraw(Gdiplus::Graphics * graphics);

private:

};

