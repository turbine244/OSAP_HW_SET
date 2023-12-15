#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. class definition for AvlTree<int>::Return_Rank test
class RankTest {
	public :

	// 1-1. Initialize tree with values (role of fixture)
	RankTest() {
		for (int i = 0; i < 15; ++i)
			avltree_.Do_Insert(i);
	}

	// 1-2. function : Return Return_Rank(value)
	int Rank_Success(int value) {
		return avltree_.Return_Rank(value);
	}

	protected : 
		AvlTree<int> avltree_;
};

// 2. class definition for Parameterized Value test
class RankParameterizedTestFixture: public testing::TestWithParam<std::tuple<int,int>> {
	protected:
		RankTest rank_test;
};


// 3. Case Definition
INSTANTIATE_TEST_CASE_P(
	RankTests,
	RankParameterizedTestFixture,
	testing::Values(std::make_tuple(0,1), std::make_tuple(1,2),
		std::make_tuple(2,3), std::make_tuple(3,4),
		std::make_tuple(4,5), std::make_tuple(5,6),
		std::make_tuple(6,7), std::make_tuple(7,8),
		std::make_tuple(8,9), std::make_tuple(9,10),
		std::make_tuple(10,11), std::make_tuple(11,12),
		std::make_tuple(12,13), std::make_tuple(13,14),
		std::make_tuple(14,15)
	)
);

// 4. Test for parameterized Value (Basic Tree)
TEST_P(RankParameterizedTestFixture, RankCheckWithParams) {
	std::tuple<int, int> tuple = GetParam();
	int param = std::get<0>(tuple);
	int expected_value = std::get<1>(tuple);

	int value = rank_test.Rank_Success(param);
	EXPECT_EQ(expected_value, value);
}	

// 6. Test for Basic tree rank with Fixture
TEST_F(UnitTestFixture, RankCheck) {
	int value = 1;
	int result = avltree_.Return_Rank(value);

	ASSERT_EQ(result, 2);
}

