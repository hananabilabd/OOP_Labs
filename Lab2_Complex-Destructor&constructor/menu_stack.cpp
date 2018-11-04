#include <iostream>
#include <stdio.h>
#include<windows.h>
//#define null -32
#include<conio.h>
using namespace std;

class Stack{
    int top;
    int stack_size;
    int * ptr ;
    static int counter;
public:
    Stack(int n =10);
    ~Stack();
    void push (int x);
    int pop (void);
    void print(void);
    static int getCounter(void);
};
int Stack::counter =0;
Stack ::Stack(int n ){
    counter ++;
    top =0 ;
    stack_size = n;
    ptr = new int[stack_size];
    cout <<"Initialized Constructor of stack of size="<<stack_size<<endl;
    cout <<"Object Number="<<counter<<endl;
}

Stack::~Stack(){
    delete[]ptr ;
    counter--;
    cout <<"Destructor of stack object Number ="<<counter<<endl;
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
void Stack::print(void){
    int i;
    for ( i=0 ; i<top;i++){
    cout<<"Stack["<<i<<"]="<<ptr[i]<<endl;
    }
}
int Stack::getCounter(void){
    return counter;
}
/////////////////////////////////////////////////Stack
void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
char menu[4][13]={"Push" ,"Pop","PrintStack","Exit"};
void display_Items(int state){
    int i ;
  gotoxy(50,5);
  for (i =0 ; i< 4 ; i++){

                if (i==state){
                    gotoxy(50,i+5);
                    textattr(20);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                    textattr(15);
                }
                else {
                    gotoxy(50,i+5);
                    textattr(15);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);

                }

		}}






int main () {

    //employee emp[5] ;
	int mainMenu=1,display=0 , create=0,exit =0 ,x=0 ,flag =1,flag2=1,i,state = 0,flag_dynamic=0,n_dynamic,print=0;
	char c ;
	char  input_string[100];

        printf("Enter Stack Size=");
        scanf("%d",&n_dynamic);
        Stack c1(n_dynamic);

while (exit !=1){
    if (mainMenu == 1 && display == 0 && create ==0 && exit ==0 ){

         if (flag ==1){
        system("cls");
        state =0;
		display_Items(state);
		}

        c=getch();
        if (c == -32){

        c = getch();
          if (c == 72 ){ //up
             system("cls");
             state--;
             if (state <0){state =3;}

		display_Items(state);

        }
        else if (c ==80  ){//down

           system("cls");
           state++;
             if (state >3){state =0;}
          display_Items(state);
        }
        else if (c == 71 ){//home

            system("cls");
            state =0;
      display_Items(state);
        }
        else if (c == 79 ){//end

           system("cls");
           state =2;
        display_Items(state);

        }
        // up = 72  down = 80  home = 71  end = 79
            mainMenu =1 ;

        }
        else if (c== 13){
            if (state == 0){
            create =1 ;
            c = 0;
            }
            else if (state ==1){

            display =1 ;
            c = 0;

        }
         else if (state ==2 ){

            print =1 ;
            c = 0;

        }
        else if (state ==3 ){

            exit =1 ;
            c = 0;

        }
        mainMenu = 0;

        }


flag =0;
}
else if  (display == 1 && create ==0 && mainMenu ==0){//pop

        int x ;
        system("cls");

        x=c1.pop();
        cout<<x<<" is Pushed"<<endl;
        printf("Press any Keys to return to the main menu\n ");
        getch();
        mainMenu =1 ;
        flag =1;
        display =0 ;
        state=0;



}
else if (mainMenu ==0 && create ==1 && display ==0 ){//push

   if (flag2 ==1){system("cls");}
    flag2 =0;
    system("cls");

    int x;

    printf("Enter Number to push in stack=");
    scanf("%d",&x);
    c1.push(x);
    printf("Enter Any Key To Return to Main Menu");
    getch();
    mainMenu =1  ;
    flag =1;
    create =0 ;
    state=0;



}
else if  (mainMenu ==0 && create ==0 && display ==0 && print ==1){//Print Stack
    mainMenu =0;
    system("cls");
    c1.print();
    cout<<"press Any Key To Return To Main Menu"<<endl;
    getch();
    mainMenu =1  ;
    flag =1;
    create =0 ;
    state=0;
}
else if  (exit ==1){
    mainMenu =0;
    system("cls");

}

	}

   return(0);
}
