#include <gtest/gtest.h>
#include <vector>
#include "../../src/avltree.cc"
#include "../../src/set.cc"

class IntegrationTestFixture : public ::testing::Test {
    // SetUp()은 각 테스트 케이스가 실행되기 전에  호출
    void SetUp() override;
    // TearDown()은 각 테스트 케이스가 실행된 후에 호출.
    void TearDown() override;

protected:
    Set<AvlTree<int>> set_;
};


