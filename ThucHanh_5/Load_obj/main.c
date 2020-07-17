#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>

GLfloat scale=1;
GLfloat translateY = -30;
GLfloat translateZ = -105;
GLuint doituong;
float quay;
char ch='1';

//Hướng dẫn https://www.youtube.com/watch?v=rF9Tud6E1yI

void loadObj(char *fname)   //Đối tượng gồm các tam giác ghép lại với nhau
{
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;

    static GLfloat dinh[100000][3];
    static GLfloat mat[100000][3];
    int f1,f2,f3,t,m1;

    doituong=glGenLists(1);
    fp=fopen(fname,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }

    int i=1;
    int j=0;

    glNewList(doituong, GL_COMPILE);
    {
        glPushMatrix();

        while(!(feof(fp)))
        {
            read = fscanf(fp,"%c",&ch);
            if(ch == 'v'){  //đọc các đỉnh
                read=fscanf(fp,"%f %f %f",&x,&y,&z);
                if(read == 3){
                    dinh[i][0]=x;
                    dinh[i][1]=y;
                    dinh[i][2]=z;
                    i++;
                }
            }

            else if(ch == 'f'){ //đọc các mặt
                read=fscanf(fp,"%f/%d/%d %f/%d/%d %f/%d/%d",&x,&t,&t,&y,&t,&t,&z,&t,&t);
                if(read==9){
                    mat[j][0]=x;
                    mat[j][1]=y;
                    mat[j][2]=z;
                    j++;
                }
            }
            else
                fscanf(fp, "\n");
            m1=j;
        }
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);//Vẽ tam giác từ các đỉnh từ các faces đã lưu trong mảng mat
        for(i=0;i<m1;i++){
            f1=mat[i][0]; f2=mat[i][1]; f3=mat[i][2];
            glVertex3f(dinh[f1][0],dinh[f1][1],dinh[f1][2]);
            glVertex3f(dinh[f2][0],dinh[f2][1],dinh[f2][2]);
            glVertex3f(dinh[f3][0],dinh[f3][1],dinh[f3][2]);
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}

void reshape(int width,int height)
{
	if (height==0)
	{
		height=1;
	}
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f,(GLfloat)width/(GLfloat)height,0.1f,1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawobj()
{
 	glPushMatrix();
 	glTranslatef(0,translateY,translateZ);
 	glScalef(scale,scale,scale);
 	glRotatef(quay,0,1,0);
 	glCallList(doituong);
 	glPopMatrix();
}

/* xử lý sự kiện bàn phím */
void keyboard (unsigned char key, int x, int y)
{
    switch (key){
        /* A, D để quay */
        case 'd': case 'D':
            quay+=5;
            glutPostRedisplay();
            break;
        case 'a': case 'A':
            quay-=5;
            glutPostRedisplay();
            break;
        /* S, W để phóng to, thu nhỏ */
        case 'w': case 'W':
            translateZ+=5;
            glutPostRedisplay();
            break;
        case 's': case 'S':
            translateZ-=5;
            glutPostRedisplay();
            break;
        /* Q, E để di chuyển vật thể theo trục y */
        case 'q': case 'Q':
            translateY+=5;
            glutPostRedisplay();
            break;
        case 'e': case 'E':
            translateY-=5;
            glutPostRedisplay();
            break;
        /* J, K để tăng giảm kích thước vật thể */
        case 'j': case 'J':
            scale+=5;
            glutPostRedisplay();
            break;
        case 'k': case 'K':
            scale-=5;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void init(void)
{
    glEnable(GL_DEPTH_TEST);// bật chức năng cho phép loại bỏ một phần của đối tượng bị che bởi đối tượng khác
    glShadeModel(GL_SMOOTH);// // thiết lập chế độ shading là smooth
    /* Tô bóng cho vật thể */
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_pos [] = {1000.0, 1000.0, 1000.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}

void display(void)
{
   	glClearColor (1.0,1.0,1.0,1.0);
   	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	glLoadIdentity();
   	drawobj();
   	glutSwapBuffers(); //swap the buffers
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,450);
	glutInitWindowPosition(20,20);
	glutCreateWindow("ObjLoader");
	init();
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
    loadObj("Seahawk.obj");
	glutMainLoop();
	return 0;
}
