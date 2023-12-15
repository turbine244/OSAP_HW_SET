# 현재 디렉토리의 모든 파일 추가
file(GLOB INTEGRATION_TEST_SOURCES "*.cc")

# integration 테스트 실행 파일 생성
add_executable(IntegrationTests ${INTEGRATION_TEST_SOURCES})
target_link_libraries(IntegrationTests common_library gtest gtest_main Set AvlTree)
