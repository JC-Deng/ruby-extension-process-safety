cmake_minimum_required(VERSION 3.16)

project(demo_ext)

find_package(Ruby REQUIRED)

set(SOURCES demo_ext.cpp)

add_library(demo_ext SHARED ${SOURCES})
set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE "CXX")
set_target_properties(demo_ext PROPERTIES PREFIX "")

target_include_directories(demo_ext PUBLIC
  ${RUBY_INCLUDE_DIRS}
)
target_link_libraries(demo_ext PUBLIC
  ${RUBY_LIBRARIES}
)

install (TARGETS demo_ext DESTINATION "${CMAKE_SOURCE_DIR}")
