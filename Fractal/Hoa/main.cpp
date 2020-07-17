#include<graphics.h>

void hoa(int x, int y, int r){
    int t=r;
    r/=2;
    if(r>5){
        setcolor(GREEN);
        hoa(x,y-t,r);
        hoa(x,y+t,r);

        setcolor(YELLOW);
        hoa(x+t,y,r);
        hoa(x-t,y,r);
    }
    circle(x,y,r);
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
