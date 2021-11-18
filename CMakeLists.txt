cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_FIND_ROOT_PATH "3rdparty/range-v3")

project(core CXX)

find_package(range-v3 REQUIRED)

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
