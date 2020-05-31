#include<graphics.h>
#include<math.h>

// Midpoint vẽ đường thẳng
void Midpoint_line(int x1,int y1,int x2, int y2){
    int a,b,x,y,p;
    a=y2-y1;
    b=-(x2-x1);
    y=y1;
    x=x1;
    putpixel(x,y,7);
    p=a+b/2;        //tính vị trí tương đối của điểm midpoint so với đường thẳng
    while(x < x2){
        if(p < 0){
            p+=a;
        }else{
            y++;
            p+=a+b;
        }
        x++;
        putpixel(x,y,7);
    }
}

void Ve8diem(int xc, int yc, int x, int y, int color)
{
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}

//Midpoint vẽ đường tròn
void Midpoint_circle(int xc, int yc, int r)
{
    int x = 0; int y = r;
    int p = 5/4 - r;
    Ve8diem(xc, yc, x, y, 7);
    while (x < y)
    {
        if (p < 0)
            p += 2*x + 3;
        else
        {
            y--;
            p += 2*(x-y) + 5;
        }
        x++;
        Ve8diem(xc, yc, x, y, 7);
    }
}

//Vẽ 4 điểm đối xứng
void Ve4diem(int xc,int yc,int x, int y,int color)
{
    putpixel(xc+x,yc+y,color);
    putpixel(xc-x,yc+y,color);
    putpixel(xc-x,yc-y,color);
    putpixel(xc+x,yc-y,color);
    delay(50);
}

//Bresenham vẽ ellipse
void Bresenham_ellipse(int x_center,int y_center,int a,int b)
{
    float p,a2,b2;
    int x,y;
    a2=pow(a,2); // a^2
    b2=pow(b,2); // b^2

    // Vẽ nhánh thứ 1 (từ trên xuống)
    x=0;
    y=b;
    p=2*((float)b2/a2)-(2*b)+1;
    while(((float)b2/a2)*x <= y)
    {
        Ve4diem(y_center,y_center,x,y,7);
        if(p<0)
        {
            p += 2*((float)b2/a2)*(2*x+3);
        }
        else{
            p += 2*((float)b2/a2)*(2*x+3) - 4*y;
            y--;
        }
        x++;
    }

    // Vẽ nhánh thứ 2 (từ dưới lên)
    y=0;
    x=a;
    p=2*((float)a2/b2)-2*a+1;
    while(((float)a2/b2)*y<=x)
    {
        Ve4diem(y_center,y_center,x,y,7);
        if(p<0)
        {
            p+= 2*((float)a2/b2)*(2*y+3);
        }
        else
        {
            p+= 2*((float)a2/b2)*(2*y+3) - 4*x;
            x--;
        }
        y++;
    }
}

// Làm tròn số
int Round(int x)
{
    return x+0.5;
}

// Midpoint vẽ ellipse
void Midpoint_ellipse(int xc,int yc, int a, int b)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = pow(a,2);
    b2 = pow(b,2);
    fx = 0;
    fy = 2 * a2 * y;
    Ve4diem(xc, yc, x, y, 7);
    p = Round(b2 -(a2*b) + (a2/4));
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        if(p<0)
        {
            p += b2*(2*x + 3);
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);
            fy -= 2*a2;
        }
        Ve4diem(xc, yc, x, y, 7);
    }
    p = Round(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    while(y>0)
    {
        y--;
        fy -= 2*a2;
        if(p >=0)
        {
            p += a2*(3-2*y);
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);
        }
        Ve4diem(xc, yc, x, y, 7);
    }
}

int main()
{
    int gm, gd=DETECT;
    initgraph(&gd,&gm,NULL);

    //Midpoint_line(10,20,100,100);
    //Midpoint_circle(100,100,50);

    Bresenham_ellipse(200,200,150,100);
    //Midpoint_ellipse(300,200,150,100);

    getch();
    closegraph();
    return 0;
}
