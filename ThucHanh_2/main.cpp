#include<graphics.h>
#include<math.h>
#include <stdio.h>

#define MAX 50
#define M_PI 3.14159265358979323846

int a[MAX][2];
int t[MAX][2];
int n;


void Taodoiduong(int a[][2]){// Tạo các đỉnh cho đối tượng 2d
    printf("Ve doi tuong 2d\n");
    printf("Nhap so dinh cua doi tuong: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Nhap x cua dinh %d: ",i+1);
        scanf("%d",&a[i][0]);
        printf("Nhap y cua dinh %d: ",i+1);
        scanf("%d",&a[i][1]);
    }
}

void Vedoituong(int a[][2]){ //Vẽ đối tượng hình học 2d bằng các đường thẳng
    int mx=getmaxx()/2;
    int my=getmaxy()/2;
    for(int i=0; i<n-1; i++){
        line(a[i][0]+mx,-a[i][1]+my,a[i+1][0]+mx,-a[i+1][1]+my);
    }
    line(a[n-1][0]+mx,-a[n-1][1]+my,a[0][0]+mx,-a[0][1]+my);
}

void Tinhtien(int a[][2], int t[][2], int n){// Tịnh tiến
    int dx, dy;
    printf("Nhap toa do x,y tinh tien: ");
    scanf("%d%d",&dx,&dy);
    for(int i=0; i<n; i++){
        t[i][0]=a[i][0] + dx;
        t[i][1]=a[i][1] + dy;
    }
    Vedoituong(t);
}

void Phepquay(int a[][2], int t[][2], int n){
    double s,c,m;
    printf("Nhap goc quay: ");
    scanf("%lf",&m);

    c=cos(m * M_PI/180);
    s=sin(m * M_PI/180);


    for(int i=0; i<n; i++){
        t[i][0] = floor(a[i][0]*c + a[i][1] * s); // x1 = x1*c + y1*s
        t[i][1] = floor(-a[i][0]*s + a[i][1] * c); // y1 = -x1*s + y1*c
    }
    Vedoituong(t);
}

void Phepcogian(int a[][2],int t[][2],int n){
    float x,y;
    printf("Nhap ti so co dan x,y:");
    scanf("%f%f",&x,&y);
    for(int i=0; i<n; i++){
        t[i][0]=a[i][0]*x;
        t[i][1]=a[i][1]*y;
    }
    Vedoituong(t);
}

int main(){
    initwindow(1000,700);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    Taodoiduong(a);
    Vedoituong(a);
    Tinhtien(a,t,n);
    Phepquay(a,t,n);
    Phepcogian(a,t,n);
    getch();
    closegraph();
    return 0;
}
