#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
    int* data = new int[argc - 1];
    int length = argc - 1;
    for(int i = 1; i < argc; ++i) data[i - 1] = atoi(argv[i]);
    //self hash
    for(int i = 0; i < length; ++i){
        if(data[data[i]] != data[i]){
            int tmp = data[data[i]];
            data[data[i]] = data[i];
            data[i] = tmp;
        }
    }
    for(int i = 0; i < length; ++i){
        printf("%d ", data[i]);
    }
    printf("\n");
    delete[] data;
    return 0;
}
