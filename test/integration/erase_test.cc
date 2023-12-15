#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. Erase test for empty tree
TEST(SetEraseCheck, EmptySetEraseValue) {
	Set<AvlTree<int>> set;

    int value = 5;
	const char* expect_result = "0\n";
	
	testing::internal::CaptureStdout();
	set.Erase(value);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output.c_str(), expect_result);
}

// 2. Erase 1, 2, 3 test for basic tree
TEST_F(IntegrationTestFixture, SetErase) {
	const char* expect_result = "1\n1\n1\n";
	testing::internal::CaptureStdout();
	set_.Erase(1);
	set_.Erase(2);
	set_.Erase(3);
	std:: string output = testing::internal::GetCapturedStdout();

        EXPECT_STREQ(output.c_str(), expect_result);
}

// 3. Erase all test for basic tree
TEST_F(IntegrationTestFixture, SetEraseAll) {
	const char* expect_result = "2\n2\n1\n2\n1\n1\n1\n1\n0\n0\n";
	testing::internal::CaptureStdout();
	for (int i = 0; i <= 9; i++)
    {
        set_.Erase(i);
    }
    
	std:: string output = testing::internal::GetCapturedStdout();

        EXPECT_STREQ(output.c_str(), expect_result);
}
