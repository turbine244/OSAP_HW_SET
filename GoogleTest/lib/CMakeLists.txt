set(SOURCES
    library_code.cc
    library_code.h
)

# 정적 라이브러리 빌드
add_library(common_library STATIC ${SOURCES})

# 라이브러리의 헤더 파일 디렉토리 추가
target_include_directories(common_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
