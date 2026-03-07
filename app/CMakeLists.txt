cmake_minimum_required(VERSION 3.10)
project(app)

set(EXECUTABLE_OUTPUT_PATH ../..)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_SOURCE_DIR}/..)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../engine.dll.a)

if(MINGW)
    get_filename_component(MINGW_BIN_DIR ${CMAKE_CXX_COMPILER} DIRECTORY)

    set(MINGW_DLLS
        "${MINGW_BIN_DIR}/libwinpthread-1.dll"
        "${MINGW_BIN_DIR}/libgcc_s_seh-1.dll"
        "${MINGW_BIN_DIR}/libstdc++-6.dll"
    )

    foreach(DLL ${MINGW_DLLS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${DLL}
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
    endforeach()
endif()