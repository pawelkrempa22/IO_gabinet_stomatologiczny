#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\48729\Desktop\Project1\Project1\funkcje.cpp"
#include <math.h>
#include <cmath>

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
		TEST_METHOD(TestOdchylenieStd)
		{
			float arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
			float result = odchylenie_std(arr);
			float expected = 1.41421; // Wartość oczekiwana 

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestLogarytmZ10)
		{
			double input = 5.0;
			double result = logarytm_z_10(input);
			double expected = log10(input);

			Assert::AreEqual(expected, result);
		}
	};
}
