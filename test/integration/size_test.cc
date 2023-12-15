#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. Size test for empty tree
TEST(SetSizeCheck, EmptySetSizeValue) {
	Set<AvlTree<int>> set;
	const char* expect_result = "0\n";
	
	testing::internal::CaptureStdout();
	set.Size();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output.c_str(), expect_result);
}

// 2. Size test for basic tree
TEST_F(IntegrationTestFixture, SetSize) {
	const char* expect_result = "10\n";

	testing::internal::CaptureStdout();
	set_.Size();
	std:: string output = testing::internal::GetCapturedStdout();

        EXPECT_STREQ(output.c_str(), expect_result);
}