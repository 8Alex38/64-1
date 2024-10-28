#include "pch.h"
#include "CppUnitTest.h"
#include "../641/641.cpp" // Замініть на шлях до вашого файлу з кодом

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std; // Додаємо цю директиву, щоб уникнути використання std::

namespace UnitTest641
{
    TEST_CLASS(UnitTest641)
    {
    public:

        void CheckEqual(double expected, double result, const char* testName) {
            if (expected == result) {
                cout << testName << " passed." << endl;
            }
            else {
                cout << testName << " failed: expected " << expected << ", got " << result << endl;
            }
        }

        void CheckEqual(int expected, int result, const char* testName) {
            if (expected == result) {
                cout << testName << " passed." << endl;
            }
            else {
                cout << testName << " failed: expected " << expected << ", got " << result << endl;
            }
        }

        TEST_METHOD(TestGetMaxAbsoluteElement)
        {
            double arr[] = { -3.5, 2.0, -1.0, 4.6, -2.3 };
            double expected = 4.6;
            double result = getMaxAbsoluteElement(arr, 5);
            CheckEqual(expected, result, "TestGetMaxAbsoluteElement");
        }

        TEST_METHOD(TestFindFirstPositiveIndex)
        {
            double arr[] = { -3.5, -2.0, 1.0, 4.6, -2.3 };
            int expected = 2; // Index of the first positive number (1.0)
            int result = findFirstPositiveIndex(arr, 5);
            CheckEqual(expected, result, "TestFindFirstPositiveIndex");
        }

        TEST_METHOD(TestFindSecondPositiveIndex)
        {
            double arr[] = { -3.5, -2.0, 1.0, 4.6, -2.3 };
            int firstPos = findFirstPositiveIndex(arr, 5);
            int expected = 3; // Index of the second positive number (4.6)
            int result = findSecondPositiveIndex(arr, 5, firstPos);
            CheckEqual(expected, result, "TestFindSecondPositiveIndex");
        }

        TEST_METHOD(TestCalculateSumBetweenPositives)
        {
            double arr[] = { -3.5, -2.0, 1.0, 4.6, -2.3 };
            int firstPos = findFirstPositiveIndex(arr, 5);
            int secondPos = findSecondPositiveIndex(arr, 5, firstPos);
            double expected = 0.0; // There are no elements between 1.0 and 4.6
            double result = calculateSumBetweenPositives(arr, firstPos, secondPos);
            CheckEqual(expected, result, "TestCalculateSumBetweenPositives");
        }

        TEST_METHOD(TestMoveNonZeroElements)
        {
            double arr[] = { 0.0, 1.0, 0.0, 2.0, 0.0 };
            int nonZeroIndex = 0;
            moveNonZeroElements(arr, 5, nonZeroIndex);
            CheckEqual(2, nonZeroIndex, "TestMoveNonZeroElements");

            // Check if non-zero elements are in correct place
            CheckEqual(1.0, arr[0], "TestMoveNonZeroElements Check 1");
            CheckEqual(2.0, arr[1], "TestMoveNonZeroElements Check 2");
        }

        TEST_METHOD(TestFillRemainingZeros)
        {
            double arr[5] = { 1.0, 2.0, 0.0, 0.0, 0.0 };
            int nonZeroIndex = 2; // After moving non-zero elements
            fillRemainingZeros(arr, 5, nonZeroIndex);

            // Check that remaining elements are filled with zeros
            CheckEqual(0.0, arr[2], "TestFillRemainingZeros Check 1");
            CheckEqual(0.0, arr[3], "TestFillRemainingZeros Check 2");
            CheckEqual(0.0, arr[4], "TestFillRemainingZeros Check 3");
        }
    };
}
