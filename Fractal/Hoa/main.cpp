#include<graphics.h>

void hoa(int x, int y, int r){
    circle(x,y,r);
    int t=r;
    r/=2;
    if(r>5){
        hoa(x,y-t,r);
        hoa(x+t,y,r);
        hoa(x,y+t,r);
        hoa(x-t,y,r);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    hoa(x,y,100);
    getch();
    closegraph();
}
