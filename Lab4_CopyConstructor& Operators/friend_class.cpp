#include <iostream>
using namespace std;
class A {
private:
    int a;
public:
    A() { a=3; }
    friend class B;     // Friend Class
};

class B {
private:
    int b;
public:
    A k ;
    void show (){
        cout<<k.a<<endl;
    }
    void showA(A& x) {
        // Since B is friend of A, it can access
        // private members of A
        cout << "A::a=" << x.a;
    }
};

int main() {
   A a;
   B b;
  b.show();
   //b.showA(a);
   return 0;
}
