cmake_minimum_required(VERSION 2.8.12)
set(PROJECT_NAME "mycoolproject")
project(${PROJECT_NAME} C CXX)

set(EXT_PROJECTS_DIR "${PROJECT_SOURCE_DIR}/ext")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")

# find_package(GLEW REQUIRED)

# include_directories(
#   ${GLEW_INCLUDE_DIRS}
#  )

# TODO include source files here
set(
  PROJECT_SOURCES
  ""
  )

add_library(
  PROJECT_LIBRARY 
  OBJECT
  ${PROJECT_SOURCES}
  )

add_executable(
  ${PROJECT_NAME}
  ${SRC_DIR}/main.cpp
  $<TARGET_OBJECTS:PROJECT_LIBRARY>
  )

#target_link_libraries(
  #${PROJECT_NAME} 
  #${GLEW_LIBRARIES}
  #)

option(test "Build all tests." ON)
if (test)
  enable_testing()
  set(PROJECT_TEST_NAME "${PROJECT_NAME}UnitTests")
  file(GLOB TEST_SRC_FILES ${TEST_DIR}/*Test.cpp)
  add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable(
    ${PROJECT_TEST_NAME}
    ${TEST_SRC_FILES}
    $<TARGET_OBJECTS:PROJECT_LIBRARY>
    )
  add_dependencies(${PROJECT_TEST_NAME} googletest)
  target_link_libraries(
    ${PROJECT_TEST_NAME}
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    pthread
    )
  GTEST_ADD_TESTS(${PROJECT_TEST_NAME} "" ${TEST_SRC_FILES})
endif()
