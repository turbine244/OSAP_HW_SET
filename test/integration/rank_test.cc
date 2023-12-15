#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. Rank test for empty tree
TEST(SetRankCheck, EmptySetRankValue) {
	Set<AvlTree<int>> set;

    int value = 5;
	const char* expect_result = "0\n";
	
	testing::internal::CaptureStdout();
	set.Rank(value);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output.c_str(), expect_result);
}

// 2. Rank all node test for basic tree
TEST_F(IntegrationTestFixture, SetRank) {
	const char* expect_result = "2 1\n1 2\n2 3\n3 4\n0 5\n3 6\n2 7\n3 8\n1 9\n2 10\n";
	testing::internal::CaptureStdout();
    for (int i = 0; i <= 9; i++)
    {
        set_.Rank(i);
    }
	std:: string output = testing::internal::GetCapturedStdout();

        EXPECT_STREQ(output.c_str(), expect_result);
}

// Class definition for Set<AvlTree<int>>::Rank test
class SetRankTest {
   public : 
	void insert(int value) {
		set_.Insert(value);
	}
        // function : return target node's depth
    std::string set_rank_success(int value) {
         testing::internal::CaptureStdout();
            set_.Rank(value);
            std::string output = testing::internal::GetCapturedStdout();

            return output.c_str();
      }
	protected :
		Set<AvlTree<int>> set_;
};

// Class definition for Parameterized Value test
class SetRankParameterizedTestFixture: public testing::TestWithParam<std::tuple<int, std::string>> {
   protected:
   void SetUp() {
	//Insert 0 to 7
	for (int i = 0; i < 8; i++)
	{
		set_rank_test.insert(i);
	}
	
   }
      SetRankTest set_rank_test;
};

// Case definition
INSTANTIATE_TEST_CASE_P(
   SetRankTests,
   SetRankParameterizedTestFixture,
   testing::Values(std::make_tuple(1,"1 2\n"), std::make_tuple(2,"2 3\n"),
      std::make_tuple(4,"2 5\n"), std::make_tuple(5,"1 6\n"),
      std::make_tuple(6,"2 7\n"), std::make_tuple(7,"3 8\n")
   )
);

// Test for Parametrized Value
TEST_P(SetRankParameterizedTestFixture, SetRankByParam) {
   std::tuple<int, std::string> tuple = GetParam();
   int param = std::get<0>(tuple);
   const char* expect_result = std::get<1>(tuple).c_str();

    std::string output = set_rank_test.set_rank_success(param);
   
    EXPECT_STREQ(output.c_str(), expect_result);
}