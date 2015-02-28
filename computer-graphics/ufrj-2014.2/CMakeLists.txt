cmake_minimum_required(VERSION 2.8.8)
project(HELLO)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(hello hello.cpp)
target_link_libraries(
	hello
	${OPENGL_LIBRARIES} 
	${GLUT_LIBRARIES}
	${GLEW_LIBRARIES}
	)
