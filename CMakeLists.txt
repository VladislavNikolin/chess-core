cmake_minimum_required(VERSION 3.12)

project(core CXX)

file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp")
add_library(core ${CORE_SRC})

target_include_directories(core
    PUBLIC include/
)

target_link_libraries(core
    PRIVATE ai
)
