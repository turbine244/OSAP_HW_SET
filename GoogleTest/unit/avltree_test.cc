#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

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

