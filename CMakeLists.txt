cmake_minimum_required(VERSION 3.15)
project(game VERSION 1.0 DESCRIPTION "SDL2 game")

file(GLOB SRC_FILES
    "src/*.cpp"
)

set(SDL2_USE_STATIC_LIBS ON)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} ${SRC_FILES})
include_directories(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
if (MSVC)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} SDL2::SDL2-static)
else ()
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
endif()

if (NOT MSVC)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Creating Debug executable")
        set(CMAKE_CXX_FLAGS "-g -Og -Wall -Wno-reorder -Wempty-body -Wignored-qualifiers -Wimplicit-fallthrough -Wmissing-field-initializers -Wsign-compare -Wtype-limits -Wuninitialized -Wshift-negative-value -pthread -fPIC -rdynamic")
    else ()
        message(STATUS "Creating Release executable")
        set(CMAKE_CXX_FLAGS "-O3 -Wall -Wno-reorder -Wempty-body -Wignored-qualifiers -Wimplicit-fallthrough -Wmissing-field-initializers -Wsign-compare -Wtype-limits -Wuninitialized -Wshift-negative-value -pthread -fPIC -rdynamic")
    endif ()
else ()
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Creating Debug executable")
        set(CMAKE_CXX_FLAGS "/Od /DEBUG /Zi /Zc:preprocessor")
    else ()
        message(STATUS "Creating Release executable")
        set(CMAKE_CXX_FLAGS "/O2 /Oi /Oy /GL /Gy /Zc:preprocessor")
    endif ()
endif ()
target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.h)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
