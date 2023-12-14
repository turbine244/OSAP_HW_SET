#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. Get_Size test for empty tree
TEST(GetSizeCheck, EmptyTreeGetSize) {
	AvlTree<int> avltree;

	ASSERT_EQ(avltree.Get_size(), 0);
}

// 2. Get_root test for basic tree
TEST_F(UnitTestFixture, BasicTreeGetSizeCheck) {		
	ASSERT_EQ(avltree_.Get_size(), 10);
}
