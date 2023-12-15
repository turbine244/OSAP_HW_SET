#include "../lib/library_code.h"
#include "test_fixture.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// 1. erase check for basic tree
TEST_F(UnitTestFixture, BasicTreeEraseCheckBySize) {
  int value = 1;
  avltree_.Do_Erase(value);

  ASSERT_EQ(9, avltree_.Get_size());
}

// 2. erase check for root
TEST_F(UnitTestFixture, BasicTreeEraseRoot) {
  int value = avltree_.Get_Root()->key;
  avltree_.Do_Erase(value);

  ASSERT_NE(value, avltree_.Get_Root()->key);
}

// 3. erase check for traverse
TEST_F(UnitTestFixture, BasicTreeEraseCheckByTraverse) {
  int value = avltree_.Get_Root()->key;
  avltree_.Do_Erase(value);

  ASSERT_THAT(InorderTraverse(avltree_.Get_Root()),
              testing::ElementsAre(0, 1, 2, 3, 5, 6, 7, 8, 9));
}
