#include <iostream>

using namespace std;

class A{
    public:
        long a;
};

class B : public A{
    public:
        long b;
};

void seta(A* data, int idx){
    data[idx].a = 2;
}

int funca(int* a){
    a[0]++;
}

int funcb(int b[]){
    b[1] += 5;
}

int main(){
    int a[5] = {2,3,4,5,6};
    int b[5] = {2,3,4,5,6};
    int* p;
    p = &a[0];
    (*p)++;
    funca(p);
    for(int i = 0; i < 5;++i){
        cout << a[i] << endl;
    }
    return 0;
}
