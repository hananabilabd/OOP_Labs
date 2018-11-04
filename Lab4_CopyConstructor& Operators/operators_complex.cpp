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
	Complex();// Constructor
	Complex operator + (Complex);
	Complex operator - (Complex);
	Complex operator + (float);
	Complex operator - (float);
	friend Complex operator + (float,Complex);// Friend Function
	friend Complex operator - (float ,Complex);
	void operator  += (Complex);
	int operator == (Complex);
	Complex operator ++();//prefix
	Complex operator ++(int);//postfix
	operator float (); // casting operator
	friend ostream &operator<<( ostream &output, const Complex &x ) ;
      friend istream &operator>>( istream  &input, Complex &x ) ;


};

void Complex :: setReal (float r){
	real =r ;
}
void Complex :: setImag(float i){
	imag = i ;
}
float Complex :: getReal (){
	return real;
}
float Complex :: getImag(){
	return imag;
}
void Complex :: print (void){
    if (imag > 0){
	cout<<real <<"+" <<imag <<"i"<<endl;}
	else {cout<<real <<imag <<"i"<<endl;}
}
void Complex ::setComplex(int r , int i){
    real = r ;
    imag = i;
}
void Complex ::setComplex(int v ){
    imag =real =v ;

}
Complex::~Complex(){
    //cout<<" The Object Destructor"<<endl;
}
Complex::Complex (){
	    real = 0;
	    imag =0;
	    //cout<<" The Object Constructor with 0 Parameters"<<endl;

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
Complex Complex:: operator + (Complex x){
    Complex z;
    z.real=real + x.real ;
    z.imag = this->imag + x.imag;
    return z ;
}
Complex Complex:: operator - (Complex x){
    Complex z;
    z.real=real - x.real ;
    z.imag = this->imag - x.imag;
    return z ;
}
Complex Complex ::operator + (float x){
    Complex z ;
    z.real = real + x;
    z.imag =imag ;
    return z ;

}
Complex Complex ::operator - (float x){
    Complex z ;
    z.real = real - x;
    z.imag =imag ;
    return z ;

}
Complex operator + (float x ,Complex a){
    Complex z ;
    z.real = x + a.real;
    z.imag = a.imag;
    return z ;
}
Complex operator - (float x ,Complex a){
    Complex z ;
    z.real = x - a.real;
    z.imag = a.imag;
    return z;
}
void Complex :: operator  += (Complex x){
    Complex z ;
    this-> real += x.real;
    this ->imag += x.imag;

}
int Complex::operator == (Complex x){
    if (real ==x.real && imag ==x.imag){
        return 1;
    }
    else {
        return 0;
    }
}
Complex Complex::operator ++(){//prefix
    real++;
    return *this;
}
Complex Complex:: operator ++(int){//postfix
    Complex temp = *this;
    real++;
    return temp;
}
Complex ::operator float (){ // casting operator
    return real;
}
istream &operator>>( istream  &input, Complex &x ) {
          cout<<"Enter First Complex Real & Imaginary=" <<endl;
          //input>> x.real >> x.imag;
         cin >> x.real >> x.imag;
         return input;
      }
ostream &operator<<( ostream &output, const Complex &x ) {
         output << "Real= " << x.real << " Imaginary= " << x.imag;
         //cout << "Real= " << x.real << " Imaginary= " << x.imag;
         return output;
      }
int main (){
	Complex c1 ,c2 , c3 ;
	float a ,b ,c ,d ;
	cout<<"Enter First Complex Real & Imaginary=" <<endl;
	cin>>a>>b;
	cout<<"Enter Second Complex Real & Imaginary=" <<endl;
	cin>>c>>d;
	c1.setComplex(a,b);
	c2.setComplex(c,d);

	c3=c1+c2;
	cout<<"c1+c2= ";
	c3.print();
	//////////////////
	c3=c1-c2;
	cout<<"c1-c2= ";
	c3.print();
	//////////////////
	c3=c1+5;
	cout<<"c1+5= ";
	c3.print();
	//////////////////
	c3=c1-5;
	cout<<"c1-5= ";
	c3.print();
	//////////////
    c3=5+c1;
	cout<<"5+c1= ";
	c3.print();
	/////////////////
	c3=5-c1;
	cout<<"5-c1= ";
	c3.print();
	//////////////

	cout<<"(c1==c2)="<<(c1==c2)<<endl;
	////////////////////
	c1+=c2;
	cout<<"c1+=c2 ==> c1=";
	c1.print();
	////////////////////
	++c1;
	cout<<"++c1 ==> c1="<<endl;

	c1.print();
	////////////////////
	c1++;
	cout<<"c1++ ==>c1=";
	c1.print();
	/////////////////
	(float)c1;
	cout<<"(float)c1 ===> c1=";
	c1.print();
    //////////////////////////////
    cin>>c1;
    cout<<c1<<endl;

}
