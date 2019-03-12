cmake_minimum_required(VERSION 3.13)
project(testing)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRCS project/main/source/*.cpp)
file(GLOB_RECURSE HDRS project/main/include/*.h)
file(GLOB_RECURSE TST project/main/test/*.hpp)


if(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s WASM=1 -s USE_WEBGL2=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s FULL_ES2=1 -s FULL_ES3=1 ${GCC_COVERAGE_COMPILE_FLAGS}")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --shell-file '${CMAKE_SOURCE_DIR}/project/web/www/index.html' ${GCC_COVERAGE_COMPILE_FLAGS}")
endif()

add_executable(${PROJECT_NAME}_main project/main/main.cpp ${SRCS} ${HDRS})

if(NOT EMSCRIPTEN)
    add_subdirectory(lib/googletest)
    add_subdirectory(lib/glfw)
    add_subdirectory(lib/glm)

    include_directories(lib/googletest/googletest/include)
    include_directories(lib/googletest/googlemock/include)
    include_directories(lib/glfw/include)
    include_directories(lib/glm/glm)

    link_directories(lib/googletest)
    link_directories(lib/glfw)
    link_directories(lib/glm)

    include_directories(project/main/include)

    add_executable(${PROJECT_NAME}_test ${TST} project/main/main_test.cpp ${SRCS} ${HDRS})
    target_link_libraries(${PROJECT_NAME}_test gtest gtest_main)
endif()

target_link_libraries(${PROJECT_NAME}_main glfw GLEW GL GLU)
