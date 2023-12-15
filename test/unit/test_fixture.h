#include <gtest/gtest.h>
#include <vector>
#include "../../src/avltree.cc"

class UnitTestFixture : public ::testing::Test {
    // SetUp()
    void SetUp() override;
    // TearDown()
    void TearDown() override;

protected:
    AvlTree<int> avltree_;
};


