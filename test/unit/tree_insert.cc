#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

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
	
	ASSERT_THAT(InorderTraverse(avltree_.Get_Root()), testing::ElementsAre(0,1,2,3,4,5,6,7,8,9,10));
}
