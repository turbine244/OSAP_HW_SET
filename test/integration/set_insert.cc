#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "test_fixture.h"
#include "../lib/library_code.h"

TEST(SetInsertionCheck, EmptySetInsertionValue) {
	Set<AvlTree<int>> set;
	int value = 5;
	const char* expect_result = "0";
	
	testing::internal::CaptureStdout();
	set.Insert(value);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output.c_str(), expect_result);
}

TEST_F(IntegrationTestFixture, SetInsertionByFind) {
	int value = 10;
	const char* expect_result = "3";

	testing::internal::CaptureStdout();
	set_.Insert(value);
	std:: string output = testing::internal::GetCapturedStdout();

        EXPECT_STREQ(output.c_str(), expect_result);
}

//TEST_F(UnitTestFixture, BasicTreeInsertionCheckBySize) {
//	int value = GenerateInteger(5);
//	avltree_.Do_Insert(value);
//
//	ASSERT_EQ(11, avltree_.Get_size());
//}

//TEST_F(UnitTestFixture, BasicTreeInsertionCheckByTraverse) {
//	int value = 10;
//	avltree_.Do_Insert(value);
//	
//	ASSERT_THAT(InorderTraverse(avltree_.Get_Root()), testing::ElementsAre(0,1,2,3,4,5,6,7,8,9,10));
//}
