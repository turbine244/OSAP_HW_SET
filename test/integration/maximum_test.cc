#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

// Test for Empty tree with insertion
TEST(SetMaximumCheck, EmptySetMaximum) {
    Set<AvlTree<int>> set;
    int value = 1;
    const char* expect_result = "1 0\n";

    set.Insert(value);

    testing::internal::CaptureStdout();
    set.Maximum(value);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_STREQ(output.c_str(), expect_result);
}

// Test for Basic tree
TEST_F(IntegrationTestFixture, BasicSetMaximum) {
    int value = 1;
    const char* expect_result = "3 3\n";

    testing::internal::CaptureStdout();
    set_.Maximum(value);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_STREQ(output.c_str(), expect_result);
}

// Class definition for Set<AvlTree<int>>::Maximum test
class SetMaximumTest {
	public : 
        // function : insert value
		void insert(int value) {
			set_.Insert(value);
		}

        // function : return maximum and maximum's depth
		std::string set_maximum_success(int value) {
            testing::internal::CaptureStdout();
			set_.Maximum(value);
            std::string output = testing::internal::GetCapturedStdout();

            return output.c_str();
		}

	protected : 
		Set<AvlTree<int>> set_;
};

// Class definition for Parameterized Value test
class SetMaximumParameterizedTestFixture: public testing::TestWithParam<std::tuple<int, std::string>> {
	protected:
		void SetUp() {
			for (int i = 0; i < 15; ++i)
				set_maximum_test.insert(i);
		}
		SetMaximumTest set_maximum_test;
};

// Case definition
INSTANTIATE_TEST_CASE_P(
	SetMaximumTests,
	SetMaximumParameterizedTestFixture,
	testing::Values(std::make_tuple(0,"0 3\n"), std::make_tuple(1,"2 3\n"),
		std::make_tuple(2,"2 3\n"), std::make_tuple(3,"6 3\n"),
		std::make_tuple(4,"4 3\n"), std::make_tuple(5,"6 3\n"),
		std::make_tuple(6,"6 3\n"), std::make_tuple(7,"14 3\n"),
		std::make_tuple(8,"8 3\n"), std::make_tuple(9,"10 3\n"),
		std::make_tuple(10,"10 3\n"), std::make_tuple(11,"14 3\n"),
		std::make_tuple(12,"12 3\n"), std::make_tuple(13,"14 3\n"),
		std::make_tuple(14,"14 3\n")
	)
);

// Test for Parametrized Value (Basic Tree)
TEST_P(SetMaximumParameterizedTestFixture, SetMaximumCheckWithParams) {
    std::tuple<int, std::string> tuple = GetParam();
	int param = std::get<0>(tuple);
	const char* expect_result = std::get<1>(tuple).c_str();
    
    std::string output = set_maximum_test.set_maximum_success(param);

    EXPECT_STREQ(output.c_str(), expect_result);
}