cmake_minimum_required(VERSION 3.20)

project(RLnet CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

file(GLOB_RECURSE RLNET_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")
add_library(RLnet ${RLNET_SRC})
target_include_directories(RLnet
  PUBLIC
    include/
)
target_link_libraries(RLnet
  PRIVATE
    Threads::Threads
)
