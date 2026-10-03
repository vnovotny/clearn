cmake_minimum_required(VERSION 3.28)
project(CLearn LANGUAGES C)

# C17 je podporované všude (GCC i MSVC); C23 jen částečně, proto zatím C17
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(MSVC)
    # /W4 = přísná varování, /utf-8 = zdroják i výstup v UTF-8
    add_compile_options(/W4 /utf-8)
else()
    # GCC/Clang (CLion, bundled MinGW-w64): přísná varování, zdroják je UTF-8 ve výchozím stavu
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(lekce/01-zaklad)
add_subdirectory(lekce/02-typy)
