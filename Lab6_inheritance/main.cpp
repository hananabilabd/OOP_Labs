#include <iostream>
#include <conio.h>;
#include<math.h>
using namespace std;
class Base{
private :
    int a;
    int b;
public :
    Base(){
        a=b=0;
        cout<<"Created Base with default Parameter Constructor"<<endl;
    }
    Base(int x){
        a=b=x;
        cout<<"Created Base with 1 Parameter Constructor"<<endl;
    }
    Base(int x , int y){
        a= x;
        b=y;
        cout<<"Created Base with 2 Parameter Constructor"<<endl;
    }
    void setA(int x){
        a=x;
    }
    void setB(int x){
        b=x;
    }
    void setAB(int x,int y){
        a=x;
        b=y;
    }
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
    int productAB(){
        return a*b;
    }
    int product(){
        return a*b;
    }
};
class Derived :public Base{
private :
    int c;
public :
    Derived():Base(){
        c=0;
        cout<<"Created Derived with default Constructor"<<endl;
    }
    Derived(int n):Base(n){
        c=n;
        cout<<"Created Derived with 1 Parameter Constructor"<<endl;
    }
    Derived(int x ,int y,int z):Base(x , y){
        c=z;
        cout<<"Created Derived with 3 Parameter Constructor"<<endl;
    }
    void setC(int x){
        c=x;
    }
    int getC(){
        return c;
    }
    int productABC(){
        return productAB()*c;
    }
    int product(){
        return getA()*getB()*c;
    }
};
class SecondDerived :public Derived{
private :
    int d;
public :
    SecondDerived():Derived(){
        cout<<"Created SecondDerived with default Constructor"<<endl;
        d=0;
    }
    SecondDerived(int n):Derived(n){
        d=n;
        cout<<"Created SecondDerived with 1 Parameters Constructor"<<endl;
    }
    SecondDerived(int x ,int y,int z,int m):Derived(x , y,z){
        d=m;
        cout<<"Created SecondDerived with 4 Parameters Constructor"<<endl;
    }
    void setD(int x){
        d=x;
    }
    int getD(){
        return d;
    }
    int productABCD(){
        return productABC()*d;
    }
        int product(){
        return getA()*getB()*getC()*d;
    }
};
void fun(Base t){
    t.setAB(4,5);
    cout<<"productAB="<<t.productAB()<<endl;
}
int main()
{
    Base base(1,2);
    Derived derived(3,4,5);
    SecondDerived second(6,7,8,9);
    cout <<base.productAB()<<endl;
    cout <<derived.productABC()<<endl;
    cout <<second.productABCD()<<endl;
    cout<<"-------------------------------------------------------"<<endl;

    cout<<"base.product()="<<base.product()<<endl;
    cout<<"derived.product()="<<derived.product()<<endl;
    cout<<"SecondDerived.product()="<<second.product()<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"derived.Base::product()="<<derived.Base::product()<<endl;
    cout<<"second.Base::product()="<<second.Base::product()<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"second.Base::product()="<<second.Base::product()<<endl;
    fun(base);
    fun(derived);
    return 0;
}
