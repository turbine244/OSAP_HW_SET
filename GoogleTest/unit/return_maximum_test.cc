#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. class definition for AvlTree<int>::Return_Maximum test
class MaximumTest {
	public :

	MaximumTest() {
		for (int i = 0; i < 15; ++i)
			avltree_.Do_Insert(i);
	}

	// 1-2. function : Return Return_Maximum(value)
	int Maximum_Success(int value) {
		return avltree_.Return_Maximum(value);
	}

	protected : 
		AvlTree<int> avltree_;
};

// 2. class definition for Parameterized Value test
class MaximumParameterizedTestFixture: public testing::TestWithParam<std::tuple<int,int>> {
	protected:
		MaximumTest maximum_test;
};


// 3. Case Definition
INSTANTIATE_TEST_CASE_P(
	MaximumTests,
	MaximumParameterizedTestFixture,
	testing::Values(std::make_tuple(0,0), std::make_tuple(1,2),
		std::make_tuple(2,2), std::make_tuple(3,6),
		std::make_tuple(4,4), std::make_tuple(5,6),
		std::make_tuple(6,6), std::make_tuple(7,14),
		std::make_tuple(8,8), std::make_tuple(9,10),
		std::make_tuple(10,10), std::make_tuple(11,14),
		std::make_tuple(12,12), std::make_tuple(13,14),
		std::make_tuple(14,14)
	)
);

// 4. Test for parameterized Value (Basic Tree)
TEST_P(MaximumParameterizedTestFixture, MaximumCheckWithParams) {
	std::tuple<int, int> tuple = GetParam();
	int param = std::get<0>(tuple);
	int expected_value = std::get<1>(tuple);

	int value = maximum_test.Maximum_Success(param);
	EXPECT_EQ(expected_value, value);
}	

// 6. Test for Basic tree insertion with Fixture #1
TEST_F(UnitTestFixture, BasicTreeMaximumCheckByRoot) {
	int root = avltree_.Get_Root()->key;
	int result = avltree_.Return_Maximum(root);

	ASSERT_EQ(result, 9);
}

// 7. Test for Basic tree insertion with Fixture #2 
TEST_F(UnitTestFixture, BasicTreeMaximumCheckByValue) {
	int value = 1;
	int result = avltree_.Return_Maximum(value);

	ASSERT_EQ(result, 3);
}

