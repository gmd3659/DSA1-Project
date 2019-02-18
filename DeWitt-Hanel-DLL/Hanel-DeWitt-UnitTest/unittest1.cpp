#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetMaze(const int** p_data, int p_width, int p_height);
__declspec(dllimport) int** GetMaze(int& p_width, int& p_height);
__declspec(dllimport) void GetNextPositions(int& xpos, int& ypos);
__declspec(dllimport) void SetStart(int xPos, int yPos);
__declspec(dllimport) void GetStart(int& xPos, int& yPos);
__declspec(dllimport) void SetEnd(int xPos, int yPos);
__declspec(dllimport) void GetEnd(int& xPos, int& yPos);

namespace HanelDeWittUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}

	};
}