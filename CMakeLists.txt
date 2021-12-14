cmake_minimum_required(VERSION 3.20)

project(core CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("3rdparty/range-v3")
add_subdirectory("3rdparty/RLnet")

file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS "source/*.hpp" "source/*.cpp")
add_library(core ${CORE_SRC})
target_include_directories(core
  PUBLIC
    include/
)
target_link_libraries(core
  PRIVATE
    range-v3::range-v3
    RLnet
)

enable_testing()

include(GoogleTest)
include(FetchContent)

FetchContent_Declare(googletest
  URL
    https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE CORE_TEST_SRC CONFIGURE_DEPENDS "test/*.hpp" "test/*.cpp")
add_executable(core_test ${CORE_TEST_SRC})
target_link_libraries(core_test
  PRIVATE
    core
    gtest_main
)
gtest_discover_tests(core_test)
