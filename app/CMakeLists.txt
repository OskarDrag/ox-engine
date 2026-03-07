cmake_minimum_required(VERSION 3.10)
project(app)

set(EXECUTABLE_OUTPUT_PATH ../..)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -static-libgcc -static-libstdc++")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_SOURCE_DIR}/..)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../engine.dll.a)

