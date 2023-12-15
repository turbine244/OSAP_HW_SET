#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

// Test for Empty tree
TEST(SetFindCheck, EmptySetFindCheck) {
    Set<AvlTree<int>> set;
    int value = 10;
    const char* expect_result = "-1\n";

    testing::internal::CaptureStdout();
	set.Find(value);
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(output.c_str(), expect_result);
}

// Test for Empty tree with insertion
TEST(SetFindCheck, EmptySetFindValue) {
    Set<AvlTree<int>> set;
    int value = 10;
    const char* expect_result = "0\n";

    set.Insert(value);

    testing::internal::CaptureStdout();
	set.Find(value);
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(output.c_str(), expect_result);
}

// Test for Basic tree
TEST_F(IntegrationTestFixture, BasicSetFindCheck) {
    int value = 10;
    const char* expect_result = "-1\n";

    testing::internal::CaptureStdout();
	set_.Find(value);
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(output.c_str(), expect_result);
}

// Test for Basic tree with insertion
TEST_F(IntegrationTestFixture, BasicSetFindByValue) {
    int value = 10;
    const char* expect_result = "3\n";

    set_.Insert(value);

    testing::internal::CaptureStdout();
	set_.Find(value);
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(output.c_str(), expect_result);
}

// Class definition for Set<AvlTree<int>>::Find test
class SetFindTest {
	public : 
        // function : return target node's depth
		std::string set_find_success(int value, Set<AvlTree<int>> set) {
			testing::internal::CaptureStdout();
            set.Find(value);
            std::string output = testing::internal::GetCapturedStdout();
            
            return output.c_str();
		}
};

// Class definition for Parameterized Value test
class SetFindParameterizedTestFixture: public testing::TestWithParam<std::tuple<int, std::string>> {
	protected:
		SetFindTest set_find_test;
};

// Case definition
INSTANTIATE_TEST_CASE_P(
	SetFindTests,
	SetFindParameterizedTestFixture,
	testing::Values(std::make_tuple(2,"-1\n"), std::make_tuple(-2,"-1\n"),
		std::make_tuple(3.0,"-1\n"), std::make_tuple(-2.79,"-1\n"),
		std::make_tuple(2147483641212,"-1\n"), std::make_tuple(-8724983274982739482,"-1\n")
	)
);

// Test for Parametrized Value (Empty Tree)
TEST_P(SetFindParameterizedTestFixture, SetFindByParam) {
    Set<AvlTree<int>> set;
	std::tuple<int, std::string> tuple = GetParam();
	int param = std::get<0>(tuple);
	const char* expect_result = std::get<1>(tuple).c_str();
    
    std::string output = set_find_test.set_find_success(param, set);

    EXPECT_STREQ(output.c_str(), expect_result);
}