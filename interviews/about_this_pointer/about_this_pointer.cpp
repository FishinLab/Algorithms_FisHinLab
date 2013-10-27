#include <iostream>
#include <string>

using namespace std;

class Point{
    public:
        Point(){
            cout << this << endl;
            cout << this + 1 << endl;
            cout << this - 1 << endl;
        }
};
/*
struct X{
    private:
        int len;
        char* ptr;
    public:
        int get_len(){
            return len;
        }
        char* get_ptr(){
            return ptr;
        }
        X& set(char*);
        X& cat(char*);
        void print();
};

X& X::set(char* pc){
    len = strlen(pc);
    ptr = new char[len];
    strcpy(ptr, pc);
    return *this;
};

X& X::cat(char* pc){
    len += strlen(pc);
    strcat(ptr, pc);
    return *this;
};
*/

int main()
{
    Point p;
    cout << &p << endl;
    return 0;
}
