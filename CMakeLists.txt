cmake_minimum_required(VERSION 3.23)
project(tp1_ihm C)

set(CMAKE_C_STANDARD 99)

add_executable(tp1_ihm main.c tp2_affichage.c tp2_firstIHM.c LED.c)
