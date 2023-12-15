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