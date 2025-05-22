#include "gtest/gtest.h"
#include "lab1.h"

using namespace std;

TEST(TestPrimeFactorization, TestHandlesPrimeNumbers) {
	vector<pair<int, int>> expected = { {17, 1} };
	EXPECT_EQ(primeFactorization(17), expected);
}

TEST(TestPrimeFactorization, TestHandlesCompositeNumbers) {
	vector<pair<int, int>> expected = { {2, 2}, {3, 1} };
	EXPECT_EQ(primeFactorization(12), expected);
}

TEST(TestEulerFunc, TestHandlesPrimeNumbers) {
	EXPECT_EQ(eulerFunc(17), 16);
}

TEST(TestEulerFunc, TestHandlesCompositeNumbers) {
	EXPECT_EQ(eulerFunc(14), 6);
}

TEST(TestEulerFunc, TestHandlesOne) {
	EXPECT_EQ(eulerFunc(1), 1);
}

TEST(TestEulerFunc, TestHandlesZero) {
	EXPECT_EQ(eulerFunc(0), 0);
}

TEST(TestEulerFunc, TestHandlesNegativeNumbers) {
	EXPECT_EQ(eulerFunc(-3), 0);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}