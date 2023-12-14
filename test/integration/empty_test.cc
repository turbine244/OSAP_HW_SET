#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. Return Empty() test for empty tree
TEST(SetEmptyCheck, EmptySetEmptyValue) {
	Set<AvlTree<int>> set;

	const char* expect_result = "1\n";
	
	testing::internal::CaptureStdout();
	set.Empty();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output.c_str(), expect_result);
}

// 2. Return Empty() test for basic tree
TEST_F(IntegrationTestFixture, SetEmpty) {
	const char* expect_result = "0\n";
	testing::internal::CaptureStdout();
	set_.Empty();
	std:: string output = testing::internal::GetCapturedStdout();

        EXPECT_STREQ(output.c_str(), expect_result);
}