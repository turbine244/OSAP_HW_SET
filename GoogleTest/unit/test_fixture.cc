#include "test_fixture.h"
#include <vector>

// SetUP
void UnitTestFixture::SetUp() {
  std::vector<int> vec = {1, 4, 7, 9, 2, 0, 3, 8, 6, 5};
  for (int elem : vec) {
    avltree_.Do_Insert(elem);
  }
}

// TearDown
void UnitTestFixture::TearDown() {}
