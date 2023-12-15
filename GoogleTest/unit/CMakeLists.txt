# 현재 디렉토리의 모든 파일 추가
file(GLOB UNIT_TEST_SOURCES "*.cc")


# unit 테스트 실행 파일 생성
add_executable(UnitTests ${UNIT_TEST_SOURCES} ../lib/library_code.cc)
target_link_libraries(UnitTests common_library ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} AvlTree Set)
target_include_directories(UnitTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
