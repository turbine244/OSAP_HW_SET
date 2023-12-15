# Add every .cc file in INTEGRATION_TEST_SOURCES
file(GLOB INTEGRATION_TEST_SOURCES "*.cc")

# Make Integration Test file (name : IntegrationTests)
add_executable(IntegrationTests ${INTEGRATION_TEST_SOURCES})

# Executable file linking
target_link_libraries(IntegrationTests common_library gtest gtest_main Set AvlTree)