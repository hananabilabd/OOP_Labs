#include <iostream>
using namespace std;
void swap_address(int *x , int * y){
    int t ;
    t = *x ;
    *x = *y ;
    *y = t;
}
void swap_reference(int &x , int & y){
    int t ;
    t = x ;
    x = y ;
    y = t;
}

int main (){

	int a ,b ;
	cout<<"Enter a=";
	cin>>a;
	cout<<"Enter b=";
	cin>>b;
	swap_address(&a,&b);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	swap_reference(a,b);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;





}
