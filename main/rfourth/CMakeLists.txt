cmake_minimum_required(VERSION 3.14)
project(r_forth VERSION 1.0)

add_executable (
        main
        main.c
        int_stack
        int_stack.c
        general_stack
        general_stack.c
        token
        token.c
        resolveActions
        resolveActions.c
)