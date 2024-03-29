#include <gl\glut.h>

int quay=0;
void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef((GLfloat)quay, 0.0, 1.0, 0.0);
    glPushMatrix();
    glutSolidCube(3.0);
    glPopMatrix();
    glFlush();
}
void ReShape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)width/(float)height;
    gluPerspective(45.0, ratio, 1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
void Init()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    GLfloat light_pos [] = {-1.0, 0.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    GLfloat ambient [] = {1.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    GLfloat diff_use [] = {0.0, 0.5, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    GLfloat shininess = 50.0f;
    glMateriali(GL_FRONT, GL_SHININESS, shininess);
}

/* xử lý sự kiện bàn phím */
void keyboard (unsigned char key, int x, int y)
{
    switch (key){
        case 'd': case 'D':
            quay+=5;
            glutPostRedisplay(); // vẽ lại
            break;
        case 'a': case 'A':
            quay-=5;
            glutPostRedisplay(); // vẽ lại
            break;
        default:
            break;
    }
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("To bong");
    Init();
    glutReshapeFunc(ReShape);
    glutDisplayFunc(RenderScene);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
