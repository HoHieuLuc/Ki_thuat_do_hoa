#include <winbgim.h>
#include<conio.h>
#include<math.h>

int Round(int y){
	return y+0.5;
}

//DDA vẽ đường thẳng
void DDA_line(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);
    float xt = dx/(float)steps;
    float yt = dy/(float)steps;

    float x=x1;
    float y=y1;
    for(int i=0; i<steps;i++){
        putpixel(x,y,7);
        x+=xt;
        y+=yt;

    }
    /*
     // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X,Y,RED);  // put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
        delay(100);          // for visualization of line-
                             // generation step by step
    */
}

//Bresenham vẽ đường thẳng
void Bresenham_line(int x1, int y1, int x2, int y2)
{
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int sx,sy;
    if(x1 < x2)
        sx=1;
    else
        sx=-1;
    if(y1 < y2)
        sy=1;
    else
        sy=-1;
    int p=dx-dy;
    while(true)
    {
        putpixel(x1,y1,7);
        if(x1==x2 && y1==y2) // Nếu 2 điểm gặp nhau thì dừng
            break;
        int p2=2*p;
        if(p2 >= -dy)
        {
            p=p-dy;
            x1+=sx; // Nếu x1 < x2 thì x1 tăng lên 1, ngược lại x1 giảm đi 1
        }
        if(p2 <= dx)
        {
            p=p+dx;
            y1+=sy; // Nếu y1 < y2 thì y1 tăng lên 1, ngược lại y1 giảm đi 1
        }
    }
}

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

void Ve8diem(int x0,int y0,int x, int y, int color)
{
      putpixel( x0 + x , y0 + y ,color);
      putpixel( x0 - x , y0 + y ,color);
      putpixel( x0 + x , y0 - y ,color);
      putpixel( x0 - x , y0 - y ,color);
      putpixel( x0 + y , y0 + x ,color);
      putpixel( x0 - y , y0 + x ,color);
      putpixel( x0 + y , y0 - x ,color);
      putpixel( x0 - y , y0 - x ,color);
}

//Bresenham vẽ đường tròn
void Bresenham_circle(int x0, int y0, int r)
{
    int x = 0; int y = r;
    int p = 3 - 2*r;
    while (x<=y)
    {
        Ve8diem(x0,y0,x,y,7);
        if (p<0) p = p + 4*x + 6;
        else
        {
            p= p + 4*(x-y) + 10;
            y--;
        }
        x++;
    }
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



int main(){
    int gd,gm; gd=DETECT;
    initgraph(&gd,&gm,NULL);

    Bresenham_line(150,200,100,150);
    DDA_line(245, 235, 245, 124);
    Midpoint_line(53,43,100,200);

    Bresenham_circle(450,250,100);
    Midpoint_circle(100,100,50);

    Bresenham_ellipse(150,100,50,20);
    Midpoint_ellipse(250,100,100,50);

    getch();
}
