cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(bookkeeper_thing LANGUAGES CXX)

cmake_policy(SET CMP0100 NEW)

set(pwd ${CMAKE_CURRENT_SOURCE_DIR})
set(source_dir ${pwd}/source)
set(include_dir ${pwd}/include)

file(GLOB source_files ${source_dir}/*.cc)
file(GLOB include_files ${include_dir}/${PROJECT_NAME}/*.hh)

find_package(Qt5
  COMPONENTS
    Gui
    Core
    Widgets
  REQUIRED
)

add_executable(${PROJECT_NAME} ${source_files} ${include_files})
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED on
    CXX_EXTENSIONS off
    AUTOMOC on
    AUTOUIC on
    AUTORCC on
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${include_dir}>
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt5::Gui
    Qt5::Core
    Qt5::Widgets
)
