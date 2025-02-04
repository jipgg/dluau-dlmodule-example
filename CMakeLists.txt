cmake_minimum_required(VERSION 3.22.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(dlmodule LANGUAGES CXX C)
add_subdirectory(extern/dluaulib-stub)
set(EXPORT_MACRO "DLMODULE_PROJECT_EXPORT")
# dll output name
set(MODULE_NAME my_module)
set(REQUIRE_DIR ${PROJECT_SOURCE_DIR}/require)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
# luau files to paste into the ouput directory
set(REQUIRE_FILES
    ${REQUIRE_DIR}/init.luau
)
# source files to build
set(SOURCE_FILES
    ${SOURCE_DIR}/module.cpp
)

add_library(module SHARED ${SOURCE_FILES})
target_compile_definitions(module PRIVATE ${EXPORT_MACRO})
target_include_directories(module PRIVATE ${SOURCE_DIR})
set_target_properties(module PROPERTIES OUTPUT_NAME ${MODULE_NAME})
target_link_libraries(module PRIVATE dluaulib-stub)
foreach(file IN LISTS REQUIRE_FILES)
    add_custom_command(TARGET module POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${file}" 
        "$<TARGET_FILE_DIR:module>"
    )
endforeach()
