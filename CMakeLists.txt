cmake_minimum_required(VERSION 3.28)
project(CLearn LANGUAGES C)

# C17 je v MSVC plně podporované; C23 jen částečně (/std:clatest), proto zatím C17
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(MSVC)
    # /W4 = přísná varování, /utf-8 = zdroják i výstup v UTF-8
    add_compile_options(/W4 /utf-8)
endif()

add_subdirectory(lekce/01-zaklad)
