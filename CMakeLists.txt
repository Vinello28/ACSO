cmake_minimum_required(VERSION 3.25)
project(repo C)

set(CMAKE_C_STANDARD 11)

add_executable(repo1
        "Data Structures/Esercizio 1.c")
add_executable(repo2
        "Data Structures/Esercizio 2.c")
add_executable(repo3
        "Data Structures/newlib.c" "Data Structures/newlib.h" "Data Structures/Esercizio 3.c")
add_executable(repo4
        "Processes and Threads/Esercizio 1.c")
add_executable(repo5
        "Processes and Threads/Esercizio 2.c")
add_executable(repo6
        "Processes and Threads/Esercizio 3.c")
add_executable(repo7
        "Processes and Threads/Esercizio 4.c")
add_executable(repo8
        "Processes and Threads/Esercizio 5.c")
add_executable(repo9
        "Processes and Threads/Esercizio 6.c")

add_executable(e1
        "Homeworks/PrintPID.c")
add_executable(e2
        "Homeworks/PrintAndModify.c")