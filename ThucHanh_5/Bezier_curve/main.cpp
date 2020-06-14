#include <graphics.h>
#include <math.h>
int x[4];
int y[4];

void bezier ()
{
    int i;
    double t,xt,yt;
    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        //https://en.wikipedia.org/wiki/B%C3%A9zier_curve
        //B(t)=(1-t)^3 * P0 + 3*(1-t)^2 * t*P1  +3*(1-t)*t^2 * P2    + t^3 * P3;
        xt = pow(1-t,3)*x[0]+3*pow(1-t,2)*t*x[1]+3*(1-t)*pow(t,2)*x[2]+pow(t,3)*x[3];
        yt = pow(1-t,3)*y[0]+3*pow(1-t,2)*t*y[1]+3*(1-t)*pow(t,2)*y[2]+pow(t,3)*y[3];
        putpixel (xt, yt,WHITE);
    }
    for (i=0; i<4; i++)
        circle (x[i], y[i], 5);
}

int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);
    outtextxy(0,0,"Nhan ENTER de sinh ra duong cong ngau nhien");
    char a;
    while(true){
        a=getch();
        if(a==13){
            cleardevice();
            for(int i=0; i<4; i++){
                x[i]=rand() % (getmaxx() + 1);
                y[i]=rand() % (getmaxy() + 1);
            }
        }
        bezier ();
    }
    getch();
    closegraph();
}
