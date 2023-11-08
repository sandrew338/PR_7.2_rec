#include "pch.h"
#include "CppUnitTest.h"
#include "..\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int* a = new int[3];
			*a = 0;
			*(a + 1) = 2;
			*(a + 2) = 3;
			Assert::AreEqual(0, SearchMin(a, 0, 0, 0));
		}
	};
}
