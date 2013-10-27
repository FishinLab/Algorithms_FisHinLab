#include <iostream>

using namespace std;

void get_mem(char** p, int num){
    *p = (char*)malloc(sizeof(char) * num);
}

char* get_mem_2(char* p, int num){
    cout << "address of copy str_2 ;" << &p << endl;
    p = (char*)malloc(sizeof(char) * num);
    return p;
}

void get_mem_3(int* z){
    *z = 5;
}

char* get_mem_4(void){
    char p[] = "hello world!";
    return p;
}

void change(int* a, int &b, int c){
    c = *a;
    b = 3;
    *a = 2;
};

void swapxy(char* a, char* b){
    int x = *a, y = *b;
    x = x + y;
    y = x - y;
    x = x - y;
    *a = x;
    *b = y;
    cout << "inner swapxy() : " << " x : " <<x << " y : " << y << endl;
    return;
}

int main()
{
    char* str = NULL;
    get_mem(&str, 100);
    strcpy(str, "hello world!");
    cout << str << endl;

    char* str_2 = NULL;
    str_2 = get_mem_2(str_2, 100);
    cout << "address str_2" << &str_2 << endl;
    strcpy(str_2, "hello world!");
    cout << str_2 << endl;
    delete str_2;
    
    int* z = new int;
    *z = 1;
    get_mem_3(z);
    cout << *z << endl;

    char* str_3 = NULL;
    str_3 = get_mem_4();
    cout << *str_3 << endl;

    int a = 1, b = 2, c = 3;
    change(&a, b, c);
    cout << "a : " << a << " b : " << b << " c : " << c << endl;

    char ax = 'a', by = 'b';
    char* x = &ax, * y = &by;
    swapxy(x, y);
    cout << "x : " << *x << " y : " << *y << endl;

    return 0;
}
