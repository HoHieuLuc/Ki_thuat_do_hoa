#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
int x[4];
int y[4];

void bezier ()
{
    int i;
    double t,xt,yt;
    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        xt = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        yt = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
        putpixel (xt, yt,WHITE);
    }
    for (i=0; i<4; i++)
        circle (x[i], y[i], 5);
}

int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);
    while(true){
        int a;
        scanf("%d",&a);
        if(a==1){
            cleardevice();
            for(int i=0; i<4; i++){
                x[i]=100 + rand() % (500 + 1 - 100);
                y[i]=100 + rand() % (500 + 1 - 100);
            }
        }
        bezier ();
    }
    getch();
    closegraph();
}
