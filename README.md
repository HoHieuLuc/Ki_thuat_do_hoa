Thực hành 1:
- Đường thẳng: Bresenham, DDA, Midpoint
- Đường tròn: Bresenham, Midpoint
- Ellipse : Bresenham, Midpoint
Thực hành 2:
- Quay, tịnh tiến, co giãn
Thực hành 3, 4, 5*:
- Đường con bezier, mặt cong bezier, tô bóng.
Thực hành 5:
- Load obj
Thực hành 6:
- Hoa fractal, cây fractal
Thực hành 7:
- mesh, voronoi


Tuần 6:
- Quay, vị tự
Tuần 7:
- Quay, tịnh tiến, co giãn, vị tự, vẽ hình vuông


y=sinx:
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int gd=DETECT,gm,mx,my;
    float x,y,k,kx;
    initgraph(&gd,&gm,NULL);

    mx=getmaxx()/2;my=getmaxy()/2;

    line(0,my,2*mx,my);
    line(mx,0,mx,2*my);

    x=0; kx=2*M_PI/mx;
    k=my/2;
    while (x<getmaxx())
    {
        y=k*sin((x-mx)*kx);
        putpixel((int)round(x),my-(int)round(y),RED);
        x=x+0.1;
       // delay(10);
    }

    getch();

    closegraph();
}
