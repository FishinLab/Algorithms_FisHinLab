#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char* argv[]){
    string data(argv[1]);
    int length = data.size();
    int s = 0, e = length - 1;
    int mid = floor((s + e) / 2);
    while(mid > 0){
        if(data[s] != data[e]){
            printf("not palindrome\n");
            break;
        }
        else{
            s++;
            e--;
        }
        mid--;
    }
    return 0;
}
