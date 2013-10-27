#include <iostream>
#include <memory.h>
#include <assert.h>

using namespace std;

class A1
{
    public: 
        int a;
        static int b;
};

class A2{
    public:
        int a;
        char c;
};

class A3{
    public:
        float a;
        char c;
};

class A4{
    public:
        float a;
        int b;
        char c;
};

class A5{
    double d;
    float a;
    char c;
    int b;
};

class Base{
    public:
        Base() {cout << "base class ctor" << endl;}
        ~Base() {cout << "base class dtor" << endl;}
        virtual void f(int) {cout << "" << endl;}
        virtual void f(double) {cout << "" << endl;} 
        virtual void q(int i = 10) {cout << "" << i <<endl;}
        void q2(int i = 10) {cout << "" << i << endl;}
};

class Derived : public Base{
    public:
        Derived() {cout << "" << endl;}
        ~Derived() {cout << "" << endl;}
        void f(double) {cout << "" << endl;}
        virtual void g(int i = 10) { cout << "" << endl;}
};

class B{
    float f;
    char p;
    int adf[3];
};

int main()
{
    cout << "size of class A1 : " << sizeof(A1) << endl;
    cout << "size of class A2 : " << sizeof(A2) << endl;
    cout << "size of class A3 : " << sizeof(A3) << endl;
    cout << "size of class A4 : " << sizeof(A4) << endl;
    cout << "size of class A5 : " << sizeof(A5) << endl;
    cout << "size of class Base : " << sizeof(Base) << endl;
    cout << "size of class Derived : " << sizeof(Derived) << endl;
    cout << "size of class B : " << sizeof(B) << endl; 
    return 0;
}
