#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char* argv[]){
    int* data = new int[argc - 1];
    for(int i = 1; i < argc; ++i) data[i - 1] = atoi(argv[i]);
    int c = 0, n = 0, flag = 0;
    fscanf(stdin, "%d ", &n);
    while(c != argc - 1){
        if(n == data[c] && 0 == flag){
            printf("%d ", data[c]);
            flag = 1;
        }else if(n != data[c] && 1 == flag){
            printf("%d ", data[c]);
            flag = 0;
        } 
        c++; 
    }

    return 0;
}
