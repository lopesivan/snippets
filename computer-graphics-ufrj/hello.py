from OpenGL.GLUT import *
from OpenGL.GL import *
from sys import argv

def init():
    glClearColor(0.0, 1.0, 0.0, 0.0)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0)
    
def display():
    glClear(GL_COLOR_BUFFER_BIT)
    glColor3f(1.0, 1.0, 1.0)
    glBegin(GL_POLYGON)
    i = 0
    for v in [[0.3,0.3],[0.7,0.3],[0.3,0.7]]:
        if i % 2 == 0:
            glColor3f(0.0, 0.0, 1.0)
        else:
            glColor3f(0.0, 1.0, 1.0)
        glVertex2fv(v)
        i += 1
    glEnd()
    glutSwapBuffers()

glutInit(argv)
glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE)
glutInitWindowSize(600,600)
glutCreateWindow("Square")
glutDisplayFunc(display)
init()
glutMainLoop()
