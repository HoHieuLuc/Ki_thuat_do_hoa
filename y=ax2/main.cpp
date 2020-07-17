
#include<graphics.h>

#include<math.h>

int main(){
    int gd=DETECT,gm,mx,my,a;
    float x,y,k,kx;
    initgraph(&gd,&gm,NULL);
    printf("Nhap a: ");
    scanf("%d",&a);
    mx=getmaxx()/2;my=getmaxy()/2;

    line(0,my,2*mx,my);
    line(mx,0,mx,2*my);

    x=0; kx=2*M_PI/mx;
    k=a*kx;
    while (x<mx)
    {
        y=k*x*x;
        putpixel((int)round(x)+mx,my-(int)round(y),7);
        putpixel(-(int)round(x)+mx,my-(int)round(y),7);
        x=x+0.005;
       // delay(10);
    }

    getch();

    closegraph();
}
