#include <iostream>
using namespace std;
class Stack{
    int top;
    int stack_size;
    int * ptr ;
    static int counter;
public:
    Stack(int   );
    ~Stack();
    void push (int x);
    int pop (void);
    static int getCounter(void);

};
int Stack::counter =0;

Stack::Stack(int n=10
              ){
    counter ++;
    top =0 ;
    stack_size = n;
    ptr = new int[stack_size];
    cout <<"Initialized Constructor of stack of size="<<stack_size<<endl;
    cout <<"Object Number="<<counter<<endl;
}
Stack::~Stack(){
    delete[]ptr ;
    cout <<"Destructor of stack object Number ="<<counter<<endl;
    counter--;

}
void Stack::push(int x){
    if (top == stack_size){
        cout<<"You have exceeded Stack size"<<endl;
    }
    else {
        ptr[top]=x;
        top++;
    }
}
int Stack::pop (void){
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
int Stack::getCounter(){
    return counter;
}
////////////////////////////////////////
int main (void){
    cout<<Stack::getCounter()<<endl;

    Stack c(12);
    cout<<Stack::getCounter()<<endl;
    c.push(5);
    c.push(11);
    c.push(44);
    cout<<c.pop()<<endl;
    Stack c2;
    c2.push(32);


    return 0;
}
