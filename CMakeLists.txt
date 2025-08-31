cmake_minimum_required(VERSION 3.25)
project(circuit-sim C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -sUSE_SDL=3")

file(GLOB SRC_FILES src/*.c)
add_executable(circuit ${SRC_FILES})
target_include_directories(circuit PRIVATE include)

set_property(TARGET circuit PROPERTY C_STANDARD 23)

if (CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set(SHELL_FILE "${CMAKE_SOURCE_DIR}/html_template/shell_minimal.html")
    set_target_properties(circuit PROPERTIES SUFFIX ".html")
    target_link_options(circuit PRIVATE
        --shell-file=${SHELL_FILE}
        -sUSE_SDL=3
        -sFULL_ES3=1
        -sALLOW_MEMORY_GROWTH=1
    )
endif()