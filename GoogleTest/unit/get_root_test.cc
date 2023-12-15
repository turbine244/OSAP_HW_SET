#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. Get_root test for empty tree
TEST(GetRootCheck, EmptyTreeGetRoot) {
	AvlTree<int> avltree;

	ASSERT_EQ(avltree.Get_Root(), nullptr);
}

// 2. Get_root test for basic tree
TEST_F(UnitTestFixture, AvlTreeConstructionCheckBySize) {		
	ASSERT_EQ(avltree_.Get_Root()->key, 4);
}
