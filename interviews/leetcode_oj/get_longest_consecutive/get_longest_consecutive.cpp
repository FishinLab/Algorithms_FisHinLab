#include <iostream>

using namespace std;

void get_longest_consecutive(int* data, int length){

}

int main(int argc, const char* argv[]){
    int length = argc - 1;
    int* data = new int[length];
    for(int i = 0; i < length; ++i){
        data[i] = atoi(argv[i + 1]);
    }
    get_longest_consecutive(data, length);
    return 0;
}
