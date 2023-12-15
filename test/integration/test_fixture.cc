#include "test_fixture.h"
#include <vector>

void IntegrationTestFixture::SetUp() {
	std::vector<int> vec = {1,4,7,9,2,0,3,8,6,5};
	for (int elem : vec) {
		set_.Insert(elem);
	}
}

void IntegrationTestFixture::TearDown() {
	
}


