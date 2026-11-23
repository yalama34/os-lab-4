cmake_minimum_required(VERSION 3.16)
project(os_lab5 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(lib1 SHARED src/lib1.c)
add_library(lib2 SHARED src/lib2.c)

set_target_properties(lib1 lib2 PROPERTIES PREFIX "")

add_executable(program1 src/program1.c)
target_link_libraries(program1 PRIVATE lib1)

add_executable(program2
    src/program2.c
    src/lib_manager.c
    src/platform/os_linux.c
)

target_link_libraries(program2 PRIVATE ${CMAKE_DL_LIBS})

add_dependencies(program2 lib1 lib2)