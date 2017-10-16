/**
 * \file Project1.h
 *
 * \author Team Jorge
 *
 * 
 */


// Project1.h : main header file for the Project1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols



/**
* CProject1App: See Project1.cpp for the implementation of this class
*/
class CProject1App : public CWinAppEx
{
public:
	CProject1App();


// Overrides
public:
	/** Auto generated function.
	*\return CProject1App::InitInstance Auto generated
	*/
	virtual BOOL InitInstance();
	/** Auto generated function.
	*\return CProject1App::ExitInstance Auto generated
	*/
	virtual int ExitInstance();

// Implementation

public:
	/// Auto generated function. 
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	/// Auto generated function. 
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	/// Auto generated function. 
	ULONG_PTR gdiplusToken;
};

/// Auto generated member variable
extern CProject1App theApp;
