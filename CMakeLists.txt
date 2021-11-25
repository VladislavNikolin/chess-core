cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

project(core CXX)

add_subdirectory("3rdparty/range-v3")

file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS "source/*.hpp" "source/*.cpp")
add_library(core ${CORE_SRC})
target_include_directories(core
  PUBLIC
    include/
)
target_link_libraries(core
  PRIVATE
    range-v3::range-v3
)

add_executable(test
    test/test.cpp
)
target_link_libraries(test
  PRIVATE
    core
)
