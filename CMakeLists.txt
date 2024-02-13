# cmake -S . -B build
# cmake --build build

option(ENABLE_TIDY "Build with tidy checks" ON)

cmake_minimum_required(VERSION 3.10)
project(hw2 LANGUAGES C CXX)
find_package(GTest REQUIRED)

if (ENABLE_TIDY)
  set(CMAKE_CXX_CLANG_TIDY
  clang-tidy;
  -checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus*,bugprone-*,performance-*,readability-*,misc-*,-bugprone-easily-swappable-parameters,-bugprone-suspicious-include,-readability-magic-numbers,-readability-duplicate-include,
  -header-filter=${CMAKE_CURRENT_SOURCE_DIR};
  )
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
add_library(common INTERFACE)
target_compile_options(common INTERFACE -gdwarf-4 -Wall -Wextra -Wshadow -Wpedantic -Wdouble-promotion -Wformat=2 -Wundef -Werror)

# Build main executable
add_executable(hw2_main src/hw2_main.c)
target_link_libraries(hw2_main PRIVATE common)
target_include_directories(hw2_main PUBLIC include)

# Build a single executable with all the tests. Used during development only, not on CodeGrade.
add_executable(run_all_tests tests/src/tests_aux.cpp tests/src/tests_validate_args.cpp tests/src/tests_image_operations.cpp tests/src/tests_valgrind.cpp)
target_include_directories(run_all_tests PUBLIC include tests/include)
target_link_libraries(run_all_tests PRIVATE gtest gtest_main pthread m)
