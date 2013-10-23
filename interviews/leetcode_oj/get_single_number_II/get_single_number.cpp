#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    int length = argc - 1;
    char** data = new char*[length];
    for(int i = 0; i < length; ++i){
        int tmp = atoi(argv[i + 1]);
        while(tmp > 0){
            
            tmp >> 1;
        }
    } 
    return 0;
}
