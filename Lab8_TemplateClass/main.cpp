#include <iostream>
using namespace std;
#include "operators_complex.h"
#define copyConstructor 1
template <class T>
class Stack{
    int top;
    int stack_size;
    T * ptr ;
    static int counter;
public:

    Stack(T n);
    #if (copyConstructor ==1)
    Stack(Stack &z);
    #endif
    ~Stack();
    void push (T x);
    T pop (void);
    static int getCounter(void);
    friend void printReference(Stack &x);
    friend void printCopy(Stack);
    void printStack();
    void operator = (Stack s);

};
template <class T>
int Stack<T>::counter =0;

template <class T>
Stack<T>::Stack(T n){
    counter ++;
    top =0 ;
    stack_size = n;
    ptr = new T[stack_size];

    cout <<"Constructor Object Number="<<counter<<endl;
}
#if (copyConstructor ==1)
template <class T>
Stack<T>::Stack(Stack &z){ //Copy Constructor
    top =z.top ;
    stack_size = z.stack_size;
    ptr = new T[stack_size];
    for (int i =0 ; i<top;i++){
        ptr[i]=z.ptr[i];//only copy values
    }
    counter ++;
    cout <<"Constructor Object Number="<<counter<<endl;
}
#endif
template <class T>
Stack<T>::~Stack(){
    delete[]ptr ;
    cout <<"Destructor of stack object Number ="<<counter<<endl;
    counter--;

}
template <class T>
void Stack<T>::push(T x){
    if (top == stack_size){
        cout<<"You have exceeded Stack size"<<endl;
    }
    else {
        ptr[top]=x;
        top++;
    }
}
template <class T>
T Stack<T>::pop (void){
    int result;
    if (top == 0){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    else {
        top--;
        result =ptr[top];
    }
    return result;
}
template <class T>
int Stack<T>::getCounter(){
    return counter;
}
template <class T>
void Stack<T>:: operator = (Stack<T> s){
    delete [] this-> ptr;
    this ->top = s.top;
    this -> stack_size = s.stack_size;
    this-> ptr = new int [stack_size];
    for (int i =0 ; i<stack_size ; i++){
        ptr[i] = s.ptr[i];
    }

}
template <class T>
void Stack<T>:: printStack(){
    int i;
    for ( i=0 ; i<top;i++){
    cout<<"Stack["<<i<<"]="<<ptr[i]<<endl;
    }
}
template <class T>
void printReference(Stack<T> &x){
    int i;
    for ( i=0 ; i<x.top;i++){
    cout<<"Stack["<<i<<"]="<<x.ptr[i]<<endl;
    }
}
template <class T>
void printCopy(Stack<T> x){
    int i;
    for ( i=0 ; i<x.top;i++){
    cout<<"Stack["<<i<<"]="<<x.ptr[i]<<endl;
    }
}

////////////////////////////////////////
int main (void){
    cout<<"Counter of int ="<<Stack<int>::getCounter()<<endl;

    Stack <int> s(12);
    s.push(3);
    s.push(5);
    s.push(4);
    s.printStack();
    cout<<"--------------------------------------------"<<endl;

    //printCopy(c);

    //printReference(c);
    //printCopy(c2);
    Stack<Complex> s2(3);
    Complex c1(2,3),c2(4,7),c3(4,-1);
    s2.push(c1);
    s2.push(c2);
    s2.push(c3);
    s2.printStack();
    cout<<"c1="<<c1<<endl;


    return 0;
}
