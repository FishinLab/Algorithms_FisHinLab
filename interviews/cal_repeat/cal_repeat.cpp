#include <iostream>

using namespace std;

int main(int argc, const char* argv){
    int data[argc - 1];
    for(int i = 1; i < argc; ++i) data[i - 1] = atoi(argv[i]);
    return 0;
}
