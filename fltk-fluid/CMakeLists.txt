# http://www.cmake.org/Wiki/CMakeForFLTK
# http://seriss.com/people/erco/fltk-videos/

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(hello)

FIND_PACKAGE(FLTK REQUIRED)
EXECUTE_PROCESS(COMMAND fluid -c "${CMAKE_CURRENT_SOURCE_DIR}/hello.fl")
FLTK_WRAP_UI(UI hello.fl)
ADD_LIBRARY(UI callbacks.cxx ${UI_FLTK_UI_SRCS})

ADD_EXECUTABLE(
  program
  custom.cxx
  )

ADD_DEPENDENCIES(program UI)
TARGET_LINK_LIBRARIES(program UI)
TARGET_LINK_LIBRARIES(program ${FLTK_LIBRARIES})
