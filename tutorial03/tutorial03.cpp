#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/math3d.h>

GLuint VB0;

static void RenderSceneCB() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBindBuffer(GL_ARRAY_BUFFER, VB0);

  glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray(0);

  glutSwapBuffers();
}

static void CreateVertexBuffer() {
  Vector3f Vertices[3];
  Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f); // bottom left
  Vertices[1] = Vector3f(0.0f, 1.0f, 0.0f); // top
  Vertices[2] = Vector3f(1.0f, -1.0f, 0.0f); // bottom right

  glGenBuffers(1, &VB0);
  glBindBuffer(GL_ARRAY_BUFFER, VB0);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA); 

  int width = 1920;
  int height = 1080;
  glutInitWindowSize(width, height);

  int x =  200;
  int y =  100;
  glutInitWindowPosition(x, y);
  int win = glutCreateWindow("Tutorial 03");
  printf("window id: %d\n", win);
 
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);

	CreateVertexBuffer();

  glutDisplayFunc(RenderSceneCB);
  glutMainLoop();

  return 0;
}
