#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[]){
    string data(argv[1]);
    int length = strlen(argv[1]);
    int start = 0, end = length - 1;
    int i = 0, mid = length / 2 + 1;
    while(i < mid){
        char tmp = data[start];
        data[start] = data[end];
        data[end] = tmp;
        start++;
        end--;
        i++; 
    }
    cout << data << endl;
    return 0;
}
