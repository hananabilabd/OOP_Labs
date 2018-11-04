#include <iostream>
using namespace std;
#define copyConstructor 1
class Stack{
    int top;
    int stack_size;
    int * ptr ;
    static int counter;
public:

    Stack(int );
    Stack(Stack &z);
    ~Stack();
    void push (int x);
    int pop (void);
    static int getCounter(void);
    friend void printReference(Stack &x);
    friend void printCopy(Stack);

};
int Stack::counter =0;

Stack::Stack(int n=10 ){
    counter ++;
    top =0 ;
    stack_size = n;
    ptr = new int[stack_size];

    cout <<"Constructor Object Number="<<counter<<endl;
}
#if (copyConstructor ==1)
Stack::Stack(Stack &z){ //Copy Constructor
    top =z.top ;
    stack_size = z.stack_size;
    ptr = new int[stack_size];
    for (int i =0 ; i<top;i++){
        ptr[i]=z.ptr[i];//only copy values
    }
    counter ++;
    cout <<"Constructor Object Number="<<counter<<endl;
}
#endif
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
void printReference(Stack &x){
    int i;
    int t =x.top;
    for ( i=0 ; i<t;i++){
    cout<<"Stack["<<i<<"]="<<x.ptr[i]<<endl;
    }
}
void printCopy(Stack x){
    int i;
    int t =x.top;
    for ( i=0 ; i<t;i++){
    cout<<"Stack["<<i<<"]="<<x.ptr[i]<<endl;
    }
}
////////////////////////////////////////
int main (void){
    //cout<<Stack::getCounter()<<endl;

    Stack c(12);
    c.push(5);
    c.push(11);
    c.push(44);
    cout<< "Pop="<<c.pop()<<endl;
    //printReference(c);
    printCopy(c);


    return 0;
}
