/**
 * \file ChildView.cpp
 *
 * \author Team jorge
 *The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */


// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Project1.h"
#include "ChildView.h"
#include "Game.h"
#include "Villain.h"
#include "Juicer.h"
#include "PokeBall.h"
#include "Arya.h"
#include "Gru.h"
#include "DoubleBufferDC.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;


/// Frame duration in milliseconds
const int FrameDuration = 30;

///Base numbers for villain drawing
const int LocationX = 300;
const int LocationY = 300;

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

/**
* This function is called to draw in the window.
*
* This function is called in response to a drawing message
* whenever we need to redraw the window on the screen.
* It is responsible for painting the window.
*/void CChildView::OnPaint()
{
	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	mGame.Update(elapsed);
	mScoreBoard.Timer(elapsed);


	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);
	SolidBrush green(Color(0, 255, 0));

	mTotalTime += elapsed;
	int seconds = (int)mTotalTime % 60;
	int minutes = mTotalTime / 60;
	wstring secondsString = to_wstring(seconds);
	if (seconds < 10) {
		secondsString = to_wstring(0) + secondsString;
	}

	wstring fullTimeFormat = to_wstring(minutes)+ L":" + secondsString;
	const wchar_t* counter = fullTimeFormat.c_str();

	graphics.DrawString(counter,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(rect.Width(), 10),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with

	//
	//// Bottom minus image size minus margin is top of the image
	//mTrashcanTop = rect.Height() - mTrashcan->GetHeight() - TrashcanMargin;
	//mTrashcanRight = TrashcanMargin + mTrashcan->GetWidth();

	//graphics.DrawImage(mTrashcan.get(), TrashcanMargin, mTrashcanTop,
	//	mTrashcan->GetWidth(), mTrashcan->GetHeight());

	/*
	* Actually Draw the city
	*/
	//mCity.OnDraw(&graphics);
	//Pen pen(Color::Green, 2);

	//for (auto tile : mCity)
	//{
	//	tile->DrawBorder(&graphics, &pen);
	//}

}


/**
*  Erase the background prior to drawing.
*
* We return true so this does nothing. This prevents the flicker
* of a repaint of white before actual drawing.
*
* \param pDC A device context to draw on
* \returns TRUE
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// This disabled the default background erase
	return TRUE;
}

/**  Called when there is a left mouse button press
* \param nFlags Flags associated with the mouse button press
* \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{

	mGame.OnLButtonDown(nFlags, point);
	Invalidate();
}

/**  Called when the mouse is moved
* \param nFlags Flags associated with the mouse movement
* \param point Where the button was pressed
*/
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	mGame.OnMouseMove(nFlags, point);
	Invalidate();
}

/**  Called when the left mouse button is released
* \param nFlags Flags associated with the mouse button release
* \param point Where the button was pressed
*/

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CWnd::OnLButtonUp(nFlags, point);
	Invalidate();

}




/**
*  Handle timer events
* \param nIDEvent The timer event ID
*/
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}
