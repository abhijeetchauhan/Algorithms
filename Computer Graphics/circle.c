#include<stdio.h>
#include<graphics.h>
 
void midc(float r,float xc,float yc);
void bresc(float r,float xc,float yc);
 
int main()
{
    float xc,yc,x,y,p,r,m,n;
    int c;
    int gdriver = DETECT, gmode;
    printf("\nEnter the radius of the circle\n");
    scanf("%f",&r);
    printf("\nEnter the centre of the circle\n");
    scanf("%f%f",&xc,&yc);
 
first:
    printf("\nOPTIONS \n1.MIDPOINT CIRCLE ALGORITHM \n2.BRESENHAM CIRCLE ALGORITHM \n3.EXIT");
    printf("\n Enter your choice:");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        initgraph(&gdriver, &gmode,"C:\\tc\\bgi");
        setbkcolor(WHITE);
        midc(r,xc,yc);
        goto first;
    case 2:
        initgraph(&gdriver, &gmode,"C:\\tc\\bgi");
        bresc(r,xc,yc);
        goto first;
    case 3:
        exit(0);
    }
    getch();
    return 0;
}
void midc(float r,float xc,float yc)
{
    float p,x,y,m,n;
    x=0;
    y=r;
    putpixel(xc+x,yc+y,2);
    putpixel(xc-x,yc+y,2);
    putpixel(xc+x,yc-y,2);
    putpixel(xc-x,yc-y,2);
    putpixel(xc+y,yc+x,2);
    putpixel(xc-y,yc+x,2);
    putpixel(xc+y,yc-x,2);
    putpixel(xc-y,yc-x,2);
    p=(5/4)-r;
    while(x<y)
    {
        if(p<0)
        {
            x=x+1;
            p=p+(2*x)+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            m=(2*x)+2;
            n=(2*y)+2;
            p=p+m+1-n;
        }
        putpixel(xc+x,yc+y,2);
        putpixel(xc-x,yc+y,2);
        putpixel(xc+x,yc-y,2);
        putpixel(xc-x,yc-y,2);
        putpixel(xc+y,yc+x,2);
        putpixel(xc-y,yc+x,2);
        putpixel(xc+y,yc-x,2);
        putpixel(xc-y,yc-x,2);
    }
    getch();
}
 
 
void bresc(float r,float xc,float yc)
{
    float p,x,y;
 
    x=0;
    y=r;
    putpixel(xc+x,yc+y,2);
    putpixel(xc-x,yc+y,2);
    putpixel(xc+x,yc-y,2);
    putpixel(xc-x,yc-y,2);
    putpixel(xc+y,yc+x,2);
    putpixel(xc-y,yc+x,2);
    putpixel(xc+y,yc-x,2);
    putpixel(xc-y,yc-x,2);
    p=3-(2*r);
    while(x<y)
    {
        if(p<0)
        {
            x=x+1;
            p=p+(4*x)+6;
        }
        else
        {
            x=x+1;
            y=y-1;
            p=p+(4*x)-(4*y)+10;
        }
        putpixel(xc+x,yc+y,2);
        putpixel(xc-x,yc+y,2);
        putpixel(xc+x,yc-y,2);
        putpixel(xc-x,yc-y,2);
        putpixel(xc+y,yc+x,2);
        putpixel(xc-y,yc+x,2);
        putpixel(xc+y,yc-x,2);
        putpixel(xc-y,yc-x,2);
    }
    getch();
}