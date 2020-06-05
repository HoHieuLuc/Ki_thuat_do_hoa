#include<graphics.h>
#include<math.h>
#include<cmath>
#include <stdio.h>

#define MAX 50
#define M_PI 3.14159265358979323846

int a[MAX][2];
int t[MAX][2];
int n;


void Taodoiduong(int a[][2]){// Tạo các đỉnh cho đối tượng 2d
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
    //for(int i=1; i<=m; i++){
        //c=cos(i * M_PI/180);
        //s=sin(i * M_PI/180);
        c=cos(m * M_PI/180);
        s=sin(m * M_PI/180);

        for(int i=0; i<n; i++){
            t[i][0] = roundf(a[i][0]*c + a[i][1] * s); // x1 = x1*c + y1*s
            t[i][1] = roundf(-a[i][0]*s + a[i][1] * c); // y1 = -x1*s + y1*c
        }
        //cleardevice();
        Vedoituong(t);
        delay(50);
    //}
}

void Phepvitu(int a[][2], int t[][2], int n){
    float k;
    int x,y;
    printf("Nhap ti so k: ");
    scanf("%f",&k);
    printf("Nhap tam O: ");
    scanf("%d%d",&x,&y);

    for(int i=0; i<n; i++){
        t[i][0] = k*(a[i][0]-x)+x;
        t[i][1] = k*(a[i][1]-y)+y;
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

void Vehinhvuong(int a[][2],int t[][2]){
    int d;
    printf("Nhap toa do x1,y1: ");
    scanf("%d%d",&a[0][0],&a[0][1]);
    printf("nhap chieu rong: ");
    scanf("%d",&d);

    a[1][0]=a[0][0]+d;  //x2
    a[1][1]=a[0][1];    //y2
    a[2][0]=a[1][0];
    a[2][1]=a[1][1]+d;
    a[3][0]=a[0][0];
    a[3][1]=a[0][1]+d;

    n=4;
    for(int i=0; i<n;i++){
        t[i][0]=a[i][0];
        t[i][1]=a[i][1];
    }
    Vedoituong(t);
}
/*
void Vehinhvuong(int x1, int y1, int d){
    int x2=x1+d;
    int y2=y1;
    double s,c;
    c=cos(45 * M_PI/180);
    s=sin(45 * M_PI/180);
    line(x1,y1,x2,y2);
    line(x2,y2,x2,y2+d);
    line(x1,y1,x1,y1+d);
    line(x2,y2+d,x1,y1+d);
}*/


int main(){
    initwindow(1000,700);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    //Taodoiduong(a);
    //Vedoituong(a);
    //Tinhtien(a,t,n);
    //Phepquay(a,t,n);
    //Phepvitu(a,t,n);
    //Phepcogian(a,t,n);
    //Vehinhvuong(100,100,50);

    Vehinhvuong(a,t);
    Phepquay(a,t,n);
    getch();
    closegraph();
    return 0;
}
