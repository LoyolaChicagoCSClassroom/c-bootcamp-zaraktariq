cmake_minimum_required(VERSION 3.14)
project(std-queue VERSION 1.0)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(wordlist-demo
        wordlist-demo.c
        wordlist.c)

add_executable(int_stack_demo
        int_stack_demo.c
        int_stack.c)

add_executable(
        int_stack_tests
        int_stack_tests.cc
        int_stack.c
)

target_link_libraries(
        int_stack_tests
        gtest_main
        -lpthread
)

include(GoogleTest)
gtest_discover_tests(int_stack_tests)