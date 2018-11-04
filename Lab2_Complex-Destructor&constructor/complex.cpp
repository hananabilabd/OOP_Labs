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
	void setComplex (int r , int i);
	void setComplex (int v);
	~Complex();
	Complex(int r , int i );
	Complex (int v);
	Complex (){
	    real = 0;
	    imag =0;
	    cout<<" The Object Constructor with 0 Parameters"<<endl;

	}

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
void Complex ::setComplex(int r , int i){
    real = r ;
    imag = i;
}
void Complex ::setComplex(int v ){
    imag =real =v ;

}
Complex::~Complex(){
    cout<<" The Object Destructor"<<endl;
}

Complex ::Complex(int r , int i){
    real =r ;
    imag = i ;
    cout<<" The Object Constructor with 2 Parameters"<<endl;
}
Complex ::Complex (int v){
    real=imag = v;
    cout<<" The Object Constructor With one Parameter"<<endl;
}

Complex add (Complex a,Complex b){
    Complex result ;
    float x;
    x=a.getReal()+b.getReal();
    result.setReal(x);
    x=a.getImag()+b.getImag();
    result.setImag(x);
    cout<<"///////////////"<<endl;
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
