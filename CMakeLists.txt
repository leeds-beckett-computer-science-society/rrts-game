cmake_minimum_required(VERSION 3.13)
project(testing)

set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig)

file(GLOB_RECURSE SRCS src/main/*.cpp)
file(GLOB_RECURSE HDRS src/include/*.h)
file(GLOB_RECURSE TST src/test/*.hpp)

add_subdirectory(lib/googletest)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(src/include)
add_executable(${PROJECT_NAME}_main src/main.cpp ${SRCS} ${HDRS})
target_link_libraries(${PROJECT_NAME}_main ${GTKMM_LIBRARIES})

add_executable(${PROJECT_NAME}_test ${TST} src/main_test.cpp ${SRCS} ${HDRS} )
target_link_libraries(${PROJECT_NAME}_test gtest gtest_main ${GTKMM_LIBRARIES})
