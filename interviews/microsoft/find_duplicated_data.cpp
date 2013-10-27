#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    int* data = new int[argc - 1]; 
    for(int i = 1; i < argc; ++i) data[i - 1] = atoi(argv[i]);
    for(int i = 0; i < argc - 1; ++i){
        if(data[data[i]] != data[i]){
            data[i] = data[data[i]];
        }
    }
    for(int i = 0; i < argc - 1; ++i){
        if(i != data[i]){
            printf("the duplicated number is : %d\n", data[data[i]]);
            break; 
        }
    }
    return 0;
}
