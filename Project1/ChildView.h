/**
 * \file ChildView.h
 *
 * \author Team Jorge
 *
 * The ChildView Class
 */

// ChildView.h : interface of the CChildView class
//


#pragma once
#include <memory>
#include "Game.h"

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()


private:							
	/// An object that describes our game
	CGame  mGame;
	/// An object that describes our game
	CScoreBoard  mScoreBoard;

	bool mFirstDraw = true; ///< True until the first time we draw
	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates											
	std::shared_ptr<CGamePiece> mGrabbedItem;
	double mTotalTime = 0;

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};