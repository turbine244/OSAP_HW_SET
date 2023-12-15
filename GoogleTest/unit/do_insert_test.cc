#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_fixture.h"
#include "../lib/library_code.h"

class InsertTest {
	public : 
		int insert_success(int value, AvlTree<int> avltree) {
			return avltree.Get_size();
		}
};

class InsertParameterizedTestFixture: public testing::TestWithParam<std::tuple<int,int>> {
	protected:
		InsertTest insert_test;
};