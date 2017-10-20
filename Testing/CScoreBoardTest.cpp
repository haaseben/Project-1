#include "stdafx.h"
#include "CppUnitTest.h"
#include "ScoreBoard.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreBoardTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}


		TEST_METHOD(TestCScoreboardConstruct)
		{
			CScoreBoard scoreboard;
		}

		TEST_METHOD(TestCScroreBoardTimer)
		{
			CScoreBoard scoreboard;
			double elapsed = 60;
			const wchar_t*  count  = nullptr;
			int TotalTime = elapsed;
			int seconds = 0;
			int minutes = 1;
			wstring secondsString = to_wstring(seconds);
			if (seconds < 10) {
				secondsString = to_wstring(0) + secondsString;
			}
			wstring fullTimeFormat = to_wstring(minutes) + L":" + secondsString;
			count = fullTimeFormat.c_str();

			Assert::IsTrue(scoreboard.mCounter ==count);


			
		}
	};
}