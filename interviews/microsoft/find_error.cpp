#include <iostream>

using namespace std;

struct s{
    int i;
    int* p;
};

int main(){
    s s;
    int* p = &s.i;
    p[0] = 4;
    p[1] = 3;
    s.p = p;
    s.p[1] = 1;
    s.p[0] = 2;
    return 0;
}
