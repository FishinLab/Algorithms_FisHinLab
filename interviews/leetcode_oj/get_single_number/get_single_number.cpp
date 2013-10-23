#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    int length = argc - 1;
    int* data = new int[length];
    for(int i = 0; i < length; ++i) data[i] = atoi(argv[i + 1]);
    int i = 1, sum = data[0];
    while(i < length){
        sum = sum ^ data[i]; 
        i++;
    }
    delete[] data;
    printf("the result is %d\n", sum);
    return 0;
}
