#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
GLfloat ctrlpoints[4][4][3] = {
    { { -1.5, -1.5, 4.0 }, { -0.5, -1.5, 2.0 }, { 0.5, -1.5, -1.0 }, { 1.5, -1.5, 2.0 }
    },
    { { -1.5, 0.5, 4.0 }, { -0.5, 0.5, 0.0 }, { 0.5, 0.5, 3.0 }, { 1.5, 0.5, 4.0 }
    },
    { { -1.5, -0.5, 1.0 }, { -0.5, -0.5, 3.0 }, { 0.5, -0.5, 0.0 }, { 1.5, -0.5, -1.0 }
    },
    { { -1.5, 1.5, -2.0 }, { -0.5, 1.5, -2.0 }, { 0.5, 1.5, 0.0 }, { 1.5, 1.5, -1.0}
    } };

int tam = 85;

/* hàm thực hiện các thao tác vẽ */
void display(void)
{
    int i, j;
    system("cls");
    if(tam>=360)
        tam=0;
    if(tam<0)
        tam=355;
    printf("Goc quay = %d",tam);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Xóa mọi pixel
    glColor3f(1.0, 1.0, 1.0);//Thiết lập màu vẽ
    glPushMatrix();// lưu lại ma trận hiện hành
    glRotatef((GLfloat)tam, 1.0, 1.0, 1.0);//Xoay 1 góc = tam
    /* vẽ 18 đường, mỗi đường được nối bởi 31 điểm */
    for (j = 0; j <= 8; j++)
    {
        glBegin(GL_LINE_STRIP);//Bắt đầu vẽ đường thẳng nối nhau
        for (i = 0; i <= 30; i++)
            glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0);//Tọa độ đỉnh
        glEnd();

        glBegin(GL_LINE_STRIP);
        for (i = 0; i <= 30; i++)
            glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);
        glEnd();
    }
    glPopMatrix();
    glFlush();
}

/* hàm thực hiện các khởi tạo */
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);//Phủ nền bằng màu đen
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_DEPTH_TEST);// bật chức năng cho phép loại bỏ một phần của đối tượng bị che bởi đối tượng khác
    glShadeModel(GL_FLAT);// thiết lập chế độ shading là flat
}

/* các thao tác cần làm khi cửa sổ bị thay đổi kích thước */
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);// thay đổi kích thước viewport
    /* xét thao tác trên chiếu */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0*(GLfloat)h / (GLfloat)w, 4.0*(GLfloat)h / (GLfloat)w, -4.0, 4.0);
    else
        glOrtho(-4.0*(GLfloat)w / (GLfloat)h, 4.0*(GLfloat)w / (GLfloat)h, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* xử lý sự kiện bàn phím */
void keyboard (unsigned char key, int x, int y)
{
    switch (key){
        case 'd': case 'D':
            tam+=5;
            glutPostRedisplay(); // vẽ lại
            break;
        case 'a': case 'A':
            tam-=5;
            glutPostRedisplay(); // vẽ lại
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);//Khởi tạo chế độ vẽ
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mat cong Bezier");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
