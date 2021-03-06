#include <iostream>
#include "g.h"
#include <conio.h>;
#include<math.h>
#include <windows.h>
#include <unistd.h>
using namespace std;

class Shape{
   private:
    int color ;
   public:
    Shape(){
        color =0;
    }
    Shape(int n){
        color =n;
    }
    void setColor(int x){
        color = x ;

    }

    int getColor(void){
        return color;
    }

};
class Point{
    int x;
    int y;
public:
    Point(){
        x =y =0;
    }
    Point (int m, int n){
        x=m;
        y=n;
    }
    void setX (int m){
        x=m;
    }
    void setY (int n){
        y=n;
    }
    void setXY(int m,int n){
        x=m;
        y=n;
    }
    int getX (){
        return x;
    }
    int getY (){
        return y;
    }
};
class Line :public Shape{//composition relation
    Point start;
    Point en;
public:
    Line() : Shape(),start(),en(){
        //cout <<"created line with default"<<endl;
    }
    Line (int x1 ,int y1,int x2,int y2) :Shape(),start(x1,y1),en(x2,y2){
        //cout <<"created line with initials"<<endl;
    }
    Line (int x1 ,int y1,int x2,int y2,int c ) :Shape(c),start(x1,y1),en(x2,y2){
        //cout <<"created line with initials"<<endl;
    }
    void setLine(int x1 ,int y1,int x2,int y2){
        start.setXY(x1,y1);
        en.setXY(x2,y2);
    }
    void setLine(int x1 ,int y1,int x2,int y2,int c){
        start.setXY(x1,y1);
        en.setXY(x2,y2);
        setColor(c);
    }
    void setLineColor(int x){
        setColor(x);
    }
    void draw(){
        setcolor(getColor());
        line(start.getX(),start.getY(),en.getX(),en.getY());
    }
};
class Rect :public Shape{
    Point ul;
    Point lr;
public:
    Rect():Shape(),ul(),lr(){
        //cout<<"Rectangle Initialized with point (0,0)"<<endl;
    }
    Rect(int x1 ,int y1 ,int x2,int y2):Shape(),ul(x1,y1),lr(x2,y2){
        //cout<<"Rectangle Initialized with given point"<<endl;
    }
    Rect(int x1 ,int y1 ,int x2,int y2,int c ):Shape(c),ul(x1,y1),lr(x2,y2){
        //cout<<"Rectangle Initialized with given point"<<endl;
    }
    void setRect (int x1 ,int y1 ,int x2,int y2){
        ul.setXY(x1,y1);
        lr.setXY(x2,y2);
    }
    void setRect (int x1 ,int y1 ,int x2,int y2,int c){
        ul.setXY(x1,y1);
        lr.setXY(x2,y2);
        setColor(c);
    }
    void setRectColor(int x){
        setColor(x);
    }
    void draw(){
        setcolor(getColor());
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }

};
class Circle :public Shape{
    Point center;
    int radius;
public:
    Circle():Shape(),center(){
        radius =0 ;
        //cout<<"Circle Initialized with point(0,0)"<<endl;
    }
    Circle(int x1 ,int y1 ,int r):Shape(),center(x1,y1){
        radius =r;
        //cout<<"Circle Initialized with given point"<<endl;
    }
    Circle(int x1 ,int y1 ,int r,int c):Shape(c),center(x1,y1){
        radius =r;
        //cout<<"Circle Initialized with given point"<<endl;
    }
    void setCircleColor(int x){
        setColor(x);
    }
    void setCircle (int x1 ,int y1 ,int r){
        radius =r;
        center.setXY(x1,y1);
    }
    void setCircle (int x1 ,int y1 ,int r,int c){
        radius =r;
        center.setXY(x1,y1);
        setColor(c);
    }
    void draw(){
        setcolor(getColor());
        circle(center.getX(),center.getY(),radius);
    }
};

class Picture{//aggregation relation
    int cNum;
    int rNum;
    int lNum;
    Circle *pCircle;
    Rect *pRectangle;
    Line *pLine;
    public:
    Picture(){
        cNum =rNum=lNum =0;
        pCircle =NULL;
        pRectangle =NULL;
        pLine =NULL;
    }
    Picture(int c ,int r , int l , Circle* pC,Rect *pR ,Line *pL){
        cNum =c;
        rNum =r;
        lNum =l;
        pCircle=pC;
        pRectangle=pR;
        pLine=pL;
    }

    void setRectangles(int x ,Rect * r){
        rNum=x;
        pRectangle=r;
    }
    void setCircles(int x,Circle *c){
        cNum=x;
        pCircle =c;
    }
    void setLines(int x , Line *l){
        lNum=x;
        pLine=l;
    }
    void draw(){
        int i ;
        for(i =0 ; i<cNum;i++){
            pCircle[i].draw();
        }
        for(i =0 ; i<rNum;i++){
            pRectangle[i].draw();
        }
        for(i =0 ; i<lNum;i++){
            pLine[i].draw();
        }

    }
};




int main()
{
    //int gdriver = DETECT, gmode, errorcode;
    //initgraph(&gdriver,&gmode,"");

    initgraph();
    /*
    Circle cArray[3]={Circle(300,90,50),Circle(600,90,50),Circle(450,200,50)};
    Rect rArray[2]={Rect(300,50,500,500),Rect(400,100,100,500)};
    Line lArray[2]={Line(300,50,500,100),Line(400,100,100,100)};
    Picture pic(3,2,2,cArray,rArray,lArray);
    pic.draw();


    setcolor(1);
    Circle c(300,90,50);
    c.draw();
    Circle c2(600,90,50);
    c2.draw();
    Circle c3(450,300,50);
    c3.draw();
    Line l(250,40,250,400);
    l.draw();
    setcolor(3);
    Line l2(650,40,650,400);
    l2.draw();
    Line l3(250,40,650,40);
    l3.draw();
    Line l4(250,400,650,400);
    l4.draw();
    Rect r(250,250,200,200);
    r.draw();
    //Rect r2(400,50,650,200);
    //r2.draw();
    */
    int s=0,m=0,cx=450,cy=250 ,color1=5,color2=3;
    float angle=-90;
    float sx,sy,mx,my;
    Line l,l2;
    Circle c(cx,cy,400,color1),c2(cx,cy,20,color2);



    while(!kbhit())
    {
    system("cls");
    s+=1;
    m+=1;
    //c.setCircle(cx,cy,400);
    //c2.setCircle(cx,cy,20);
    c.draw();
    //setcolor(5);
    c2.draw();


    sx=cx+(200)*cos((angle+s*4-6)*M_PI/180);
    sy=cy+(200)*sin((angle+s*4-6)*M_PI/180);
    l.setLine(cx,cy,sx,sy,7);
    l.draw();

    mx=cx+100*cos((angle+m*0.1+(m*30/60))*M_PI/180);//M_Pi this is the Pi
    my=cy+100*sin((angle+m*0.1+(m*30/60))*M_PI/180);
    l2.setLine(cx,cy,mx,my,9);
    l2.draw();


    usleep( 2 * 1000 );

    }
    getch();
    return 0;
}
