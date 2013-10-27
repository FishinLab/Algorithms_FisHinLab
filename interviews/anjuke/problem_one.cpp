#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    char* data = const_cast<char*>(argv[1]);
    int length = strlen(data);
    int sum, mul;
    sum = 0; mul = 1;
    for(int i = 0; i < length; ++i){
        sum += (int)data[i] - '0';
        mul *= (int)data[i] - '0';
    }
    printf("%f\n", (float)mul / sum);
     
    return 0;
}
