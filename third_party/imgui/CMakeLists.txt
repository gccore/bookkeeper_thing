cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(ImGUI LANGUAGES C)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB source_files
  source/*.cpp
  misc/cpp/*.cpp
  freetype/*.cpp
)
file(GLOB header_files
  include/*.h
  misc/cpp/*.h
  freetype/*.h
)

add_library(${PROJECT_NAME}
  STATIC
    ${source_files}
    ${header_files}
)
add_library(gccore::library::ImGUI ALIAS ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    C_STANDARD 11
    C_EXTENSIONS off
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    OpenGL::GL
    glfw
)
