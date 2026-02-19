cmake_minimum_required(VERSION 3.10)
project(engine)

set(LIBRARY_OUTPUT_PATH ../..)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)



add_library(${PROJECT_NAME} SHARED
            dependencies/glad/glad.c         
            dependencies/stb/stb_image.cpp
            ${SOURCES} 
)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" IMPORT_PREFIX "")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/dependencies)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/dependencies/GLFW/libglfw3.a
    opengl32
    gdi32
    user32
    shell32
)

target_compile_definitions(${PROJECT_NAME} PRIVATE LIBRARY_EXPORTS)