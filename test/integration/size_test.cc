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

// Class definition for Set<AvlTree<int>>::Size test
class SetSizeTest {
   public : 
        // function : return target node's depth
      std::string set_size_success(int value, Set<AvlTree<int>> set) {
         testing::internal::CaptureStdout();
            set.Size();
            std::string output = testing::internal::GetCapturedStdout();

            return output.c_str();
      }
};

// Class definition for Parameterized Value test
class SetSizeParameterizedTestFixture: public testing::TestWithParam<std::tuple<int, std::string>> {
   protected:
      SetSizeTest set_size_test;
};

// Case definition
INSTANTIATE_TEST_CASE_P(
   SetSizeTests,
   SetSizeParameterizedTestFixture,
   testing::Values(std::make_tuple(2,"0\n"), std::make_tuple(-2,"0\n"),
      std::make_tuple(3.0,"0\n"), std::make_tuple(-2.79,"0\n"),
      std::make_tuple(2147483641212,"0\n"), std::make_tuple(-8724983274982739482,"0\n")
   )
);

// Test for Parametrized Value (Empty Tree)
TEST_P(SetSizeParameterizedTestFixture, SetSizeByParam) {
    Set<AvlTree<int>> set;
   std::tuple<int, std::string> tuple = GetParam();
   int param = std::get<0>(tuple);
   const char* expect_result = std::get<1>(tuple).c_str();

    std::string output = set_size_test.set_size_success(param, set);
   
    EXPECT_STREQ(output.c_str(), expect_result);
}