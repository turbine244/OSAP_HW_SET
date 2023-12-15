#include "../lib/library_code.h"
#include "test_fixture.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

// 1. Return Empty() test for empty tree
TEST(SetEmptyCheck, EmptySetEmptyValue) {
  Set<AvlTree<int>> set;

  const char *expect_result = "1\n";

  testing::internal::CaptureStdout();
  set.Empty();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_STREQ(output.c_str(), expect_result);
}

// 2. Return Empty() test for basic tree
TEST_F(IntegrationTestFixture, SetEmpty) {
  const char *expect_result = "0\n";
  testing::internal::CaptureStdout();
  set_.Empty();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_STREQ(output.c_str(), expect_result);
}

// Class definition for Set<AvlTree<int>>::Empty test
class SetEmptyTest {
public:
  std::string set_empty_success(int value, Set<AvlTree<int>> set) {
    testing::internal::CaptureStdout();
    set.Empty();
    std::string output = testing::internal::GetCapturedStdout();

    return output.c_str();
  }
};

// Class definition for Parameterized Value test
class SetEmptyParameterizedTestFixture
    : public testing::TestWithParam<std::tuple<int, std::string>> {
protected:
  SetEmptyTest set_empty_test;
};

// Case definition
INSTANTIATE_TEST_CASE_P(
    SetEmptyTests, SetEmptyParameterizedTestFixture,
    // expect_result is 0 (Empty Tree)
    testing::Values(std::make_tuple(2, "0\n"), std::make_tuple(-2, "0\n"),
                    std::make_tuple(3.0, "0\n"), std::make_tuple(-2.79, "0\n"),
                    std::make_tuple(2147483641212, "0\n"),
                    std::make_tuple(-8724983274982739482, "0\n")));

// Test for Parametrized Value (Empty Tree)
TEST_P(SetEmptyParameterizedTestFixture, SetEmptyByParam) {
  Set<AvlTree<int>> set;
  std::tuple<int, std::string> tuple = GetParam();
  int param = std::get<0>(tuple);
  const char *expect_result = std::get<1>(tuple).c_str();

  std::string output = set_empty_test.set_empty_success(param, set);

  EXPECT_STREQ(output.c_str(), expect_result);
}