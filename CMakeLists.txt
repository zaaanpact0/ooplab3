cmake_minimum_required(VERSION 3.10)
project(FiguresProgram)

set(CMAKE_CXX_STANDARD 17)

include_directories(includes)

add_executable(figures_program 
    main.cpp 
    src/figure.cpp
    src/triangle.cpp 
    src/hexagon.cpp 
    src/octagon.cpp 
    src/array.cpp
)

add_executable(figures_tests 
    tests/tests.cpp 
    src/figure.cpp
    src/triangle.cpp 
    src/hexagon.cpp 
    src/octagon.cpp 
    src/array.cpp
)
target_compile_definitions(figures_tests PRIVATE STANDALONE_TESTS)

if(MSVC)
    target_compile_options(figures_program PRIVATE /W4)
    target_compile_options(figures_tests PRIVATE /W4)
else()
    target_compile_options(figures_program PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(figures_tests PRIVATE -Wall -Wextra -pedantic)
endif()