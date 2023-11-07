#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.1-a.it/lab 7.1-a.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
    public:
        TEST_METHOD(TestMethod1)
        {
            int matrix[ROWS][COLS];
            int min = -17;
            int max = 14;
            Generate(matrix, min, max);
            int originalMatrix[ROWS][COLS];
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    originalMatrix[i][j] = matrix[i][j];
                }
            }

            int count = 0;
            int sum = 0;
            Apply(matrix, count, sum);
            bool matrixChanged = false;
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    if (originalMatrix[i][j] != matrix[i][j]) {
                        matrixChanged = true;
                        break;
                    }
                }
                if (matrixChanged) {
                    break;
                }
            }
            Assert::IsTrue(matrixChanged);
        }
    };
}
