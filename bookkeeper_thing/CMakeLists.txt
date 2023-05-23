cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(bookkeeper_thing LANGUAGES CXX)

set(pwd ${CMAKE_CURRENT_SOURCE_DIR})
set(source_dir ${pwd}/source)
set(include_dir ${pwd}/include)

file(GLOB source_files ${source_dir}/*.cc)
file(GLOB include_files ${include_dir}/${PROJECT_NAME}/*.hh)

add_executable(${PROJECT_NAME} ${source_files} ${include_files})
