#include "../lib/library_code.h"
#include "test_fixture.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// 1. Basic Construction test by root
TEST(AvlTreeCheck, AvlTreeConstructionCheckByRoot) {
  AvlTree<int> avltree;

  ASSERT_EQ(avltree.Get_Root(), nullptr);
}

// 2. Basic Construction test by size
TEST(AvlTreeCheck, AvlTreeConstructionCheckBySize) {
  AvlTree<int> avltree;

  ASSERT_EQ(avltree.Get_size(), 0);
}
