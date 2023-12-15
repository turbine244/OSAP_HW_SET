#include "../lib/library_code.h"
#include "test_fixture.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class InsertTest {
public:
  int insert_success(int value, AvlTree<int> avltree) {
    return avltree.Get_size();
  }
};

class InsertParameterizedTestFixture
    : public testing::TestWithParam<std::tuple<int, int>> {
protected:
  InsertTest insert_test;
};

INSTANTIATE_TEST_CASE_P(
    InsertTests, InsertParameterizedTestFixture,
    testing::Values(std::make_tuple(2, 1), std::make_tuple(-2, 1),
                    std::make_tuple(3.0, 1), std::make_tuple(-2.79, 1),
                    std::make_tuple(2147483641212, 1),
                    std::make_tuple(-8724983274982739482, 1)));

TEST_P(InsertParameterizedTestFixture, TreeInsertionCheckWithParams) {
  AvlTree<int> avltree;
  std::tuple<int, int> tuple = GetParam();
  int param = std::get<0>(tuple);
  int expected_value = std::get<1>(tuple);

  avltree.Do_Insert(param);
  int value = insert_test.insert_success(param, avltree);
  EXPECT_EQ(expected_value, value);
}

TEST(TreeInsertionCheck, EmptyTreeInsertionSize) {
  AvlTree<int> avltree;
  int value = GenerateInteger(5);
  avltree.Do_Insert(value);

  ASSERT_EQ(1, avltree.Get_size());
}

TEST(TreeInsertionCheck, EmptyTreeInsertionRoot) {
  AvlTree<int> avltree;
  int value = 4;
  avltree.Do_Insert(value);

  ASSERT_EQ(value, avltree.Get_Root()->key);
}

TEST_F(UnitTestFixture, BasicTreeInsertionCheckBySize) {
  int value = GenerateInteger(5);
  avltree_.Do_Insert(value);

  ASSERT_EQ(11, avltree_.Get_size());
}

TEST_F(UnitTestFixture, BasicTreeInsertionCheckByTraverse) {
  int value = 10;
  avltree_.Do_Insert(value);

  ASSERT_THAT(InorderTraverse(avltree_.Get_Root()),
              testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
}