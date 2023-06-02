cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(bookkeeper_thing LANGUAGES CXX)

set(pwd ${CMAKE_CURRENT_SOURCE_DIR})
set(source_dir ${pwd}/source)
set(include_dir ${pwd}/include)

file(GLOB source_files
  ${source_dir}/*.cc
  ${source_dir}/widgets/*.cc
  ${source_dir}/structs/*.cc
)
file(GLOB include_files
  ${include_dir}/${PROJECT_NAME}/*.hh
  ${include_dir}/${PROJECT_NAME}/widgets/*.hh
  ${include_dir}/${PROJECT_NAME}/structs/*.hh
)

add_executable(${PROJECT_NAME} ${source_files} ${include_files})
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED on
    CXX_EXTENSIONS off
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${include_dir}>
)
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    GCCORE_IMGUI_FONT_PATH="${pwd}/../third_party/font/iosevka.ttf"
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    gccore::library::ImGUI
)
