#include <cstdio>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
using namespace std;

void init() {
	glClearColor(1.0, 0.1, 0.5, 1.0);
}

void mouseFunc(int b, int s, int x, int y) {
	printf("Mouse click position: (%d, %d)\n", x, y);
	switch (b) {
		case GLUT_LEFT_BUTTON:
			if (s == GLUT_DOWN)
				printf("Left button, down\n");
			else if (s == GLUT_UP)
				printf("Left button, up\n");
			break;
	}
}

void passiveMotionFunc(int x, int y) {
	printf("Mouse position: (%d, %d)\n", x, y);
}

void keyboardFunc(unsigned char key, int x, int y) {
	printf("Pressed ASCII code: %d, @(%d, %d) position \n", key, x, y);
	switch (key) {
		case 27:  // ESC
		case 'q':
			exit(0);
			break;
	}
}

void reshapeFunc(int width, int height) {
	printf("New window size: %d x %d\n", width, height);
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 2.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* const float v[16] = {2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0}; */
	const float v[16] = {1.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0};
	glLoadMatrixf(v);
	glutPostRedisplay();
}

void idleFunc() {}

void mySquare() {
	float w[4][3] = {
	    {1.25, 0.25}, {1.75, 0.25}, {1.75, 0.75}, {1.25, 0.75}};
	glColor4f(0.0, 0.0, 1.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3fv(w[0]);
	glVertex3fv(w[1]);
	glVertex3fv(w[2]);
	glVertex3fv(w[3]);
	glEnd();
}

void mySquare2() {
	float w[4][3] = {
		{-1.0,-1.0},{1.0,-1.0},{1.0,1.0},{-1.0,1.0}};
	glColor4f(1.0, 1.0, 0.0, 1.0);
	glPushMatrix();
	glLoadIdentity();
	glRotatef(20.0,0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(w[0]);
	glVertex3fv(w[1]);
	glVertex3fv(w[2]);
	glVertex3fv(w[3]);
	glEnd();
	glPopMatrix();
}

void myTriangle() {
	float v[3][3] = {{-1.0, -1.0, -0.1}, {1.0, 0.0, 0.0}, {0.5, -0.5, 0.0}};
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glEnd();
}

void myFigures() {
	float v[3][3] = {{-1.0, -1.0, -0.1}, {1.0, 0.0, 0.0}, {0.5, -0.5, 0.0}};
	glColor3f(0.0, 1.0, 1.0);

	glBegin(GL_POINTS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();

	/* glBegin(GL_LINE_STRIP); */
	/* glBegin(GL_LINE_LOOP); */
	glBegin(GL_POLYGON);
	glVertex2f(-0.25,0.25);
	glVertex2f(0.25,-0.25);
	/* glColor3f(0.0, 0.0, 0.0); */
	glVertex2f(0.25,0.25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1.25,0.25);
	glVertex2f(1.25,-0.25);
	/* glColor3f(0.0, 0.0, 0.0); */
	glVertex2f(1.25,0.25);
	glEnd();
	
	/* glBegin(GL_LINES); */
	/* glColor3f(1.0, 1.0, 0.0); */
	/* glVertex2f(-0.25,0.25); */
	/* glVertex2f(0.25,-0.25); */
	/* glVertex2f(0.25,-0.25); */
	/* glVertex2f(0.25,0.25); */
	/* glEnd(); */

}

void displayFunc() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* myTriangle(); */
	mySquare();
	mySquare2();
	myFigures();
	/* glRectf(0.0, 0.0, -0.85, -0.85); */
	glutSwapBuffers();
	glFlush(); // execucao em ambiente de rede???
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	/* glutInitContextVersion(3, 0); */
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(displayFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
	glutIdleFunc(idleFunc);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseFunc);
	glutReshapeFunc(reshapeFunc);

	if(glewInit()) {
		cerr << "Unable to initialize GLEW...aborting." << endl;
		exit(EXIT_FAILURE);
	}

	glutMainLoop();
	printf("You'll never reach here, actually!");
	return 0;
}
