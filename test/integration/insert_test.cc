#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

// Test for Empty tree
TEST(SetInsertionCheck, EmptySetInsertionDepth) {
	Set<AvlTree<int>> set;
	int value = 5;
	const char* expect_result = "0\n";
	
	testing::internal::CaptureStdout();
	set.Insert(value);
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(output.c_str(), expect_result);
}

// Test for Empty tree's size
TEST(SetInsertionCheck, EmptySetInsertionSize) {
	Set<AvlTree<int>> set;
	int value = 5;
	const char* expect_result = "1\n";

	set.Insert(value);
	
	testing::internal::CaptureStdout();
	set.Size();
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(output.c_str(), expect_result);
}

// Test for Basic tree
TEST_F(IntegrationTestFixture, BasicSetInsertionCheckByDepth) {
	int value = 10;
	const char* expect_result = "3\n";

	testing::internal::CaptureStdout();
	set_.Insert(value);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output.c_str(), expect_result);
}

// Test for Basic tree's size
TEST_F(IntegrationTestFixture, BasicSetInsertionCheckBySize) {
	int value = 10;
	const char* expect_result = "11\n";

	set_.Insert(value);
	
	testing::internal::CaptureStdout();
	set_.Size();
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(output.c_str(), expect_result);
}

// Class definition for Set<AvlTree<int>>::Insert test
class SetInsertTest {
	public: 
		std::string set_insert_success(int value, Set<AvlTree<int>> set) {
			testing::internal::CaptureStdout();
			set.Insert(value);
			std::string output = testing::internal::GetCapturedStdout();
			
			return output.c_str();
		}
};

// Class definition for Parameterized Value test
class SetInsertParameterizedTestFixture: public testing::TestWithParam<std::tuple<int, std::string>> {
	protected:
		SetInsertTest set_insert_test;
};

// Case definition
INSTANTIATE_TEST_CASE_P(
	SetInsertTests,
	SetInsertParameterizedTestFixture,
	testing::Values(std::make_tuple(2,"0\n"), std::make_tuple(-2,"0\n"),
		std::make_tuple(3.0,"0\n"), std::make_tuple(-2.79,"0\n"),
		std::make_tuple(2147483641212,"0\n"), std::make_tuple(-8724983274982739482,"0\n")
	)
);

// Test for Parametrized Value (Empty Tree)
TEST_P(SetInsertParameterizedTestFixture, SetInsertionByParam) {
    Set<AvlTree<int>> set;
	std::tuple<int, std::string> tuple = GetParam();
	int param = std::get<0>(tuple);
	const char* expect_result = std::get<1>(tuple).c_str();
    
	std::string output = set_insert_test.set_insert_success(param, set);

    EXPECT_STREQ(output.c_str(), expect_result);
}