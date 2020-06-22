#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
int t=0;

void tree(){
    glBegin(GL_LINES);
        glVertex2f(0, -1);
        glVertex2f(0, 0);
    glEnd();
    glRotatef(45,1,0,0);
    t++;
    if(t<5)
    tree();
}



void display(void)
{
   	glClearColor (0.0,0.0,0.0,1.0);
   	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	glLoadIdentity();
   	tree();
   	glutSwapBuffers(); //swap the buffers
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(20,20);
	glutCreateWindow("ObjLoader");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
