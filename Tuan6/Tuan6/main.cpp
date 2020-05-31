#include<graphics.h>
#include<math.h>

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
    for(int i=0; i<n-1; i++){
        line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]); // Nối đỉnh hiện tại với đỉnh tiếp theo
    }
    line(a[n-1][0],a[n-1][1],a[0][0],a[0][1]);// Nối đỉnh cuối cùng với đỉnh đầu tiên
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

void Phepvitu(int a[][2], int t[][2], int n){
    float k;
    printf("Nhap ti so k: ");
    scanf("%f",&k);

    for(int i=0; i<n; i++){
        t[i][0] = a[i][0]*k;
        t[i][1] = a[i][1]*k;
    }
    Vedoituong(t);
}

int main(){
    int gm, gd=DETECT;
    initgraph(&gd,&gm,NULL);

    Taodoiduong(a);
    Vedoituong(a);
    Phepquay(a,t,n);
    Phepvitu(a,t,n);

    getch();
    closegraph();
    return 0;
}
