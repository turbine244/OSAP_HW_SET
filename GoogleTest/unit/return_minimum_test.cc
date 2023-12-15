#include "../lib/library_code.h"
#include "test_fixture.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// 1. class definition for AvlTree<int>::Return_Minimum test
class MinimumTest {
public:
  // 1-1. Initialize tree with values (role of fixture)
  MinimumTest() {
    for (int i = 0; i < 15; ++i)
      avltree_.Do_Insert(i);
  }

  // 1-2. function : Return Return_Minimum(value)
  int Minimum_Success(int value) { return avltree_.Return_Minimum(value); }

protected:
  AvlTree<int> avltree_;
};

// 2. class definition for Parameterized Value test
class MinimumParameterizedTestFixture
    : public testing::TestWithParam<std::tuple<int, int>> {
protected:
  MinimumTest minimum_test;
};

// 3. Case Definition
INSTANTIATE_TEST_CASE_P(
    MinimumTests, MinimumParameterizedTestFixture,
    testing::Values(std::make_tuple(0, 0), std::make_tuple(1, 0),
                    std::make_tuple(2, 2), std::make_tuple(3, 0),
                    std::make_tuple(4, 4), std::make_tuple(5, 4),
                    std::make_tuple(6, 6), std::make_tuple(7, 0),
                    std::make_tuple(8, 8), std::make_tuple(9, 8),
                    std::make_tuple(10, 10), std::make_tuple(11, 8),
                    std::make_tuple(12, 12), std::make_tuple(13, 12),
                    std::make_tuple(14, 14)));

// 4. Test for parameterized Value (Basic Tree)
TEST_P(MinimumParameterizedTestFixture, MinimumCheckWithParams) {
  std::tuple<int, int> tuple = GetParam();
  int param = std::get<0>(tuple);
  int expected_value = std::get<1>(tuple);

  int value = minimum_test.Minimum_Success(param);
  EXPECT_EQ(expected_value, value);
}

// 6. Test for Basic tree insertion with Fixture #1
TEST_F(UnitTestFixture, BasicTreeMinimumCheckByRoot) {
  int root = avltree_.Get_Root()->key;
  int result = avltree_.Return_Minimum(root);

  ASSERT_EQ(result, 0);
}

// 7. Test for Basic tree insertion with Fixture #2
TEST_F(UnitTestFixture, BasicTreeMinimumCheckByValue) {
  int value = 3;
  int result = avltree_.Return_Maximum(value);

  ASSERT_EQ(result, 3);
}
