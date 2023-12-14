#include "pch.h"
#include "CppUnitTest.h"
#include"../kalkulator/funkcje.cpp"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(log_nat(5.0), log(5.0));
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(exponent(5.0), exp(5.0));
		}
		/*TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(odchylenie_std(tab), );
		}*/
	};
}
