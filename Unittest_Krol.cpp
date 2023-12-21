#include "pch.h"
#include "CppUnitTest.h"
#include "../Kalkulator/funkcje.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KalkulatorUnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestLogarytmNaturalny)
        {
            // Arrange
            double x = 5.0;

            // Act
            double result = Funkcje::logarytmNaturalny(x);

            // Assert
            double expected = log(x);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestWartoscExponentu)
        {
            // Arrange
            double x = 5.0;

            // Act
            double result = Funkcje::wartoscExponentu(x);

            // Assert
            double expected = exp(x);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestOdchylenieStandardowe)
        {
            // Arrange
            double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            int n = sizeof(arr) / sizeof(arr[0]);

            // Act
            double result = Funkcje::odchylenieStandardowe(arr, n);

            // Assert
            double expected = 1.41421; // Wartość oczekiwana 
            double epsilon = 0.00001; // Adjusted epsilon

            Assert::AreEqual(expected, result, epsilon);
        }

        TEST_METHOD(TestMaxValue)
        {
            // Arrange
            double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            int n = sizeof(arr) / sizeof(arr[0]);

            // Act
            double result = Funkcje::maxValue(arr, n);

            // Assert
            double expected = 5.0; // Maksymalna wartość w tablicy

            Assert::AreEqual(expected, result);
        }
    };
}
