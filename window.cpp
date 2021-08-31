#include <GL/freeglut.h>
#include <stdio.h>

//callback for glutDisplayFunc
static void RenderSceneCB()
{
  static GLclampf c = 0.0f; 
  glClearColor(c, c, c, c);
  printf("%f \n", c);
  c += 1.0f/256.0f;

  if(c >= 1.0f){
    c = 0.0f;
  }

  glClear(GL_COLOR_BUFFER_BIT);
  glutPostRedisplay();
  glutSwapBuffers();
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
  int win = glutCreateWindow("First window");
  printf("window id: %d\n", win);
  
  glutDisplayFunc(RenderSceneCB);
  glutMainLoop();

  return 0;
}
