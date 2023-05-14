cmake_minimum_required(VERSION 3.25)
project(repo C)

set(CMAKE_C_STANDARD 11)

add_executable(repo1
        "Data Structures/Esercizio 1.c")
add_executable(repo2
        "Data Structures/Esercizio 2.c")
add_executable(repo3
        "Data Structures/newlib.c" "Data Structures/newlib.h" "Data Structures/Esercizio 3.c")
