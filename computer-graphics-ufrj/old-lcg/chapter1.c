#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#define WINDOW_TITLE_PREFIX "Chapter 1"

int CurrentWidth = 800,
	CurrentHeight = 600,
	WindowHandle = 0;

void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction(void);

int main(int argc, char* argv[])
{
	printf("Início da main!\n");
	//printf("%x\n", GLUT_HAS_MOUSE);
	//printf("%x\n", GLUT_HAS_JOYSTICK);

	Initialize(argc, argv);

	glutMainLoop();

	printf("Fim da main!\n");
	exit(EXIT_SUCCESS); //sai do programa
	// return 0;
}

void Initialize(int argc, char* argv[])
{
	InitWindow(argc, argv);

	fprintf(
		stdout,
		"INFO: OpenGL Version: %s\n",
		glGetString(GL_VERSION)
	);

	printf("INFO: OpenGL Renderer %s\n", glGetString(GL_RENDERER));
	printf("INFO: OpenGL Shading Language Version %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("INFO: OpenGL Vendor %s\n", glGetString(GL_VENDOR));

	glClearColor(0.0f,0.0f,0.0f,0.0f); // black
	glClearColor(0.5f, 0.7f, 0.2f, 1.0f); // green
}

/* FreeGLUT: criar uma janela */
void InitWindow(int argc, char* argv[])
{
	glutInit(&argc, argv); // inicializa a biblioteca freGLUT

	glutInitContextVersion(3, 0); // define o contexto do OpenGL
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);  // isso faz com que NÃO seja permitido utilizar as versões deprecated
	glutInitContextProfile(GLUT_CORE_PROFILE); // escolheu o core: trabalhando com a versão atual! Alternativa: COMPATIBILITY

//
	// seta uma opção no estilo de atributo
	glutSetOption(
		GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS
	);
	// essa opção específica: ao fechar a janela: volta a main, em vez de
	// sair do programa para confirmar isso, basta colocar um print depois 
	// do loop da glut

	glutInitWindowSize(CurrentWidth, CurrentHeight);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); //poderíamos
	// acrescentar mais opções ainda aqui
	
	// depth buffer: Z-buffer (3D)
	// double: double buffering --> to reduce image flickering
	// front buffer vs end buffer

	WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

	if(WindowHandle < 1) {
		fprintf(
			stderr,
			"ERROR: Could not create a new rendering window.\n"
		);
		exit(EXIT_FAILURE);
	}
	
	// AQUI: CONTEXTO OPENGL VÁLIDO E SETADO!!!! PODEMOS DESENHAR

	// definindo callbacks: as funções que fazem tal coisa
	// tratado internamente com function pointers
	glutReshapeFunc(ResizeFunction); // window resize
	glutDisplayFunc(RenderFunction); // scene rendering
}

void ResizeFunction(int Width, int Height)
{
	CurrentWidth = Width;
	CurrentHeight = Height;
	printf("New Width x Height: %d x %d\n", CurrentWidth, CurrentHeight);
	glViewport(0, 0, CurrentHeight, CurrentHeight);
}

void RenderFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();
	glutPostRedisplay();
}

