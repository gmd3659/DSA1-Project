#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
__declspec(dllimport) char* GetTeam();
__declspec(dllimport) bool SetMaze(const int** p_data, int p_width, int p_height);
__declspec(dllimport) int** GetMaze(int& p_width, int& p_height);
__declspec(dllimport) bool GetNextPosition(int& xpos, int& ypos);
__declspec(dllimport) bool SetStart(int xPos, int yPos);
__declspec(dllimport) bool GetStart(int& xPos, int& yPos);
__declspec(dllimport) bool SetEnd(int xPos, int yPos);
__declspec(dllimport) bool GetEnd(int& xPos, int& yPos);

namespace HanelDeWittUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		//GetTeam Tests
		TEST_METHOD(TestGetTeamNotNull)
		{
			//Check for a non null string
			Assert::IsNotNull(GetTeam());
		}
		

		//SetMaze Tests
		TEST_METHOD(TestSetMaze)
		{
			// TODO: Your test code here
			const int** m = new const int*[3];
			for (int i = 0; i < 3; i++) 
			{ 
				m[i] = new int[4];
			}
			Assert::IsTrue(SetMaze(m, 4, 3));

		}

		//GetMaze Tests
		TEST_METHOD(TestGetMaze)
		{
			// TODO: Your test code here
			int width = 3;
			int height = 4;

			Assert::IsNotNull(GetMaze(width, height));

		}

		//GetNextPosition Tests
		TEST_METHOD(TestGetNextPosition)
		{
			// TODO: Your test code here
			int width = 3;
			int height = 4;

			Assert::IsTrue(GetNextPosition(width, height));
		}

		//SetStart Tests
		TEST_METHOD(TestSetStartBadX)
		{
			//Checks for invalid x
			int x = -1;
			int y = 0;

			Assert::IsFalse(SetStart(x, y));
		}

		TEST_METHOD(TestSetStartBadY)
		{
			//Checks for invalid y
			int x = 0;
			int y = -1;

			Assert::IsFalse(SetStart(x, y));
		}

		//GetStart Tests
		TEST_METHOD(TestGetStartBadX)
		{
			//Checks for invalid x

			int x = -1;
			int y = 0;

			Assert::IsTrue(GetStart(x, y));
		}

		TEST_METHOD(TestGetStartBadY)
		{
			//Checks for invalid y

			int x = 0;
			int y = -1;

			Assert::IsTrue(GetStart(x, y));
		}

		//Set End Tests
		TEST_METHOD(TestSetEndBadX)
		{
			//Checks for invalid x
			int x = -1;
			int y = 0;

			Assert::IsFalse(SetEnd(x, y));
			
		}

		TEST_METHOD(TestSetEndBadY)
		{
			//Checks for invalid y
			int x = 0;
			int y = -1;

			Assert::IsFalse(SetEnd(x, y));
			
		}

		//GetEnd Tests
		TEST_METHOD(TestGetEndX)
		{
			//Checks for invalid x

			int x = -1;
			int y = 0;

			Assert::IsTrue(GetEnd(x, y));
			
		}

		TEST_METHOD(TestGetEndY)
		{
			//Checks for invalid y

			int x = 0;
			int y = -1;

			Assert::IsTrue(GetEnd(x, y));
		}

		TEST_METHOD(TestRestart) 
		{

		}
	};
}