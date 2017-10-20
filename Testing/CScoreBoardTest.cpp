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

		TEST_METHOD(TestCScroreBoardAryaScore)
		{
			CScoreBoard scoreboard;
			scoreboard.SetAryaScore(3);

			Assert::IsTrue(scoreboard.GetAryaScore()==3);


			
		}
	};
}