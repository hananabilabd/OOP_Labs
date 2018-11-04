#include <iostream>
#include <conio.h>;
#include<math.h>
using namespace std;
//M_PI is Pi from Math
class GeoShape{
protected:
    float dim1;
    float dim2;
public:
    GeoShape(){
        dim1=dim2=0;
        cout<<"GeoShape Constructor with Default Parameters"<<endl;
    }
    GeoShape(float x){
        dim1=dim2=x;
        cout<<"GeoShape Constructor with 1 Parameters"<<endl;
    }
    GeoShape(float x,float y){
        dim1=x;
        dim2=y;
        cout<<"GeoShape Constructor with 2 Parameters"<<endl;
    }
    ~GeoShape(){
        cout<<"Destructor of GeoShape"<<endl;
    }
    void setDim1(float x){
        dim1=x;
    }
    void setDim2(float x){
        dim2=x;
    }
    void setDim1_2(float x,float y){
        dim1=x;
        dim2=y;
    }
    float getDim1(void){
        return dim1;
    }
    float getDim2(void){
        return dim2;
    }
    virtual float calculateArea()=0;

};
class Triangle :public GeoShape{
  public :
    Triangle() :GeoShape(){
        cout<<"Triangle Constructor with Default Parameters"<<endl;
    }
    Triangle(float s,float h) :GeoShape(s,h){
        cout<<"Triangle Constructor with 2 Parameters"<<endl;
    }
    ~Triangle(){
        cout<<"Destructor of Triangle"<<endl;
    }
    float calculateArea(){
        cout<<"Triangle calculateArea"<<endl;
        return 0.5 *dim1*dim2;
    }
};
class Rect :public GeoShape{
  public:
    Rect():GeoShape(){
        cout<<"Rectangle Constructor with Default Parameters"<<endl;
    }
    Rect(float x ,float y):GeoShape(x,y){
        cout<<"Rectangle Constructor with 2 Parameters"<<endl;
    }
    ~Rect(){
        cout<<"Destructor of Rectangle"<<endl;
    }
    float calculateArea(){
        cout<<"Rectangle calculateArea"<<endl;
        return  dim1*dim2;
    }
};

class Circle : public GeoShape{
public:
    Circle():GeoShape(){
        cout<<"Circle Constructor with Default Parameters"<<endl;
    }
    Circle(float x):GeoShape(x){
        cout<<"Circle Constructor with 1 Parameters"<<endl;
    }
    ~Circle(){
        cout<<"Destructor of Circle"<<endl;
    }
    void setRadius(float r){
        dim1=dim2=r;
    }
    float getRadius(){
        return dim1;
    }
    float calculateArea(){
        cout<<"Circle calculateArea"<<endl;
        return  M_PI*dim1*dim1;
    }
};
class Square : public Rect{
public :
    Square():Rect(){
        cout<<"Square Constructor with Default Parameters"<<endl;
    }
    Square(float x):Rect(x,x){
        cout<<"Square Constructor with 1 Parameters"<<endl;
    }
    ~Square(){
        cout<<"Destructor of Square"<<endl;
    }
    void setSquareDim(float x){
        dim1=dim2=x;
    }
    float getSquareDim(){
        return dim1;
    }
    float calculateArea(){
        cout<<"Square calculateArea"<<endl;
        return  dim1*dim1;
    }
};
float SumAreas (GeoShape *p1 ,GeoShape *p2 ,GeoShape *p3 ){
    return p1->calculateArea() + p2->calculateArea() +p3->calculateArea();
}
float sumOfAreas(int n , GeoShape **p){
    float sum =0;
    for (int i=0; i<n;i++){
        sum +=p[i]->calculateArea();
    }
    return sum;
}
int main()
{
    Circle c1(3);
    Triangle t1(3,4);
    Square s1(3);
    Rect r1(4,5);
    /*
    GeoShape *ptr;//Parent of smaller size Pointers can point to can child of larger size // But Child of greater size can't point to smaller size of parent
    ptr =&r1;
    cout<<"c1.calculateArea()="<<c1.calculateArea()<<endl;
    cout<<"r1.calculateArea()="<<r1.calculateArea()<<endl;
    cout<<"s1.calculateArea()="<<s1.calculateArea()<<endl;
    cout<<"t1.calculateArea()="<<t1.calculateArea()<<endl;
    */
    cout<<SumAreas(&c1,&t1,&s1)<<endl;
    //GeoShape f; This is wrong as we are calling abstract class
    GeoShape * ptr;
    ptr=&c1;
    cout<<ptr->calculateArea()<<endl;
    GeoShape **p;
    p=new GeoShape*[3];
    p[0]=&c1;
    p[1]=&t1;
    p[2]=&s1;
    cout<<sumOfAreas(3,p)<<endl;



    return 0;
}
