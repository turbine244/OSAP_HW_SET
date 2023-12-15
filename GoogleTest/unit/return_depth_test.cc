#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

// 1. Return depth test for empty tree
TEST(ReturnDepthCheck, EmptyTreeDepth) {
	AvlTree<int> avltree;

	ASSERT_EQ(avltree.Return_Depth(2), 0);
}

// 2. Get_root test for basic tree
TEST_F(UnitTestFixture, BasicTreeReturnDepth) {		
	ASSERT_EQ(avltree_.Return_Depth(3), 3);
}
