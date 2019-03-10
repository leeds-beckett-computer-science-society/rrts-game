cmake_minimum_required(VERSION 3.13)
project(testing)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRCS project/source/*.cpp)
file(GLOB_RECURSE HDRS project/include/*.h)
file(GLOB_RECURSE TST project/test/*.hpp)


if(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -s WASM=1 -s USE_WEBGL2=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s FULL_ES2=1 -s FULL_ES3=1 -s USE_SDL=2 ${GCC_COVERAGE_COMPILE_FLAGS}")
endif()

add_executable(${PROJECT_NAME}_main project/main.cpp ${SRCS} ${HDRS})

if(NOT EMSCRIPTEN)
    add_subdirectory(lib/googletest)
    #add_subdirectory(lib/SDL2-2.0.9)

    include_directories(lib/googletest/googletest/include)
    include_directories(lib/googletest/googlemock/include)
    #include_directories(lib/SDL2-2.0.9/include)

    include_directories(project/include)

    add_executable(${PROJECT_NAME}_test ${TST} project/main_test.cpp ${SRCS} ${HDRS})
    target_link_libraries(${PROJECT_NAME}_test gtest gtest_main)
endif()

target_link_libraries(${PROJECT_NAME}_main SDL2 GLEW GL OpenGL GLU)