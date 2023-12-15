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

// Class definition for Set<AvlTree<int>>::Erase test
class SetEraseTest {
   public :
	void insert(int value) {
		set_.Insert(value);
	}
    std::string set_erase_success(int value) {
         testing::internal::CaptureStdout();
            set_.Erase(value);
            std::string output = testing::internal::GetCapturedStdout();

            return output.c_str();
      }
	protected :
		Set<AvlTree<int>> set_;
};

// Class definition for Parameterized Value test
class SetEraseParameterizedTestFixture: public testing::TestWithParam<std::tuple<int, std::string>> {
   protected:
   void SetUp() {
	//Insert 0 to 7
	for (int i = 0; i < 8; i++)
	{
		set_erase_test.insert(i);
	}
	
   }
      SetEraseTest set_erase_test;
};

// Case definition
INSTANTIATE_TEST_CASE_P(
   SetEraseTests,
   SetEraseParameterizedTestFixture,
   testing::Values(std::make_tuple(1,"1\n"), std::make_tuple(2,"2\n"),
      std::make_tuple(4,"2\n"), std::make_tuple(5,"1\n"),
      std::make_tuple(6,"2\n"), std::make_tuple(7,"3\n")
   )
);

// Test for Parametrized Value
TEST_P(SetEraseParameterizedTestFixture, SetEraseByParam) {
   std::tuple<int, std::string> tuple = GetParam();
   int param = std::get<0>(tuple);
   const char* expect_result = std::get<1>(tuple).c_str();

    std::string output = set_erase_test.set_erase_success(param);
   
    EXPECT_STREQ(output.c_str(), expect_result);
}