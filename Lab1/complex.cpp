#include <iostream>
using namespace std;
class Complex{ // default of class is private
	private:
	float real ;
	float imag ;
	public :
	void setReal (float);
	void setImag (float);
	float getReal(void) ;
	float getImag (void);
	void print(void);

};
void Complex :: setReal (float i){
	imag =i ;
}
void Complex :: setImag(float i){
	real = i ;
}
float Complex :: getReal (){
	return real;
}
float Complex :: getImag(){
	return imag;
}
void Complex :: print (void){
    if (imag > 0){
	cout<< "Complex Number ="<<real <<"+" <<imag <<"i"<<endl;}
	else {cout<< "Complex Number ="<<real <<imag <<"i"<<endl;}
}
Complex add (Complex a,Complex b){
    Complex result ;
    float x;
    x=a.getReal()+b.getReal();
    result.setReal(x);
    x=a.getImag()+b.getImag();
    result.setImag(x);
    return result ;
}
Complex subtract (Complex a,Complex b){
    Complex result ;
    float x;
    x=a.getReal()-b.getReal();
    result.setReal(x);
    x=a.getImag()-b.getImag();
    result.setImag(x);
    return result ;
}

int main (){
	Complex c1 ,c2 , result1 ,result2 ;
	float a ,b ,c ,d ;
	cout<<"Enter First Complex Real & Imaginary=" <<endl;
	cin>>a>>b;
	cout<<"Enter Second Complex Real & Imaginary=" <<endl;
	cin>>c>>d;
	c1.setReal(a);
	c1.setImag(b);
	c2.setReal(c);
	c2.setImag(d);
	result1 =add(c1,c2);
    result2 =subtract(c1,c2);
    cout<<"Result of Addition=";
	result1.print();
	cout<<"Result of Subtraction=";
	result2.print();

}
