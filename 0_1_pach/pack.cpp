#include <iostream>

using namespace std;

void do_combination(int* data, int length, int start){
    if(0 == length) return;
    else{
        for(int i = start; i < length; ++i){
             
        }
        length--;
        start++;
        do_combination(data, start, length);
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int* data = new int[n];

    for(int i = 0; i < n; ++i){
        data[i] = i; 
    }
    do_combination(data, length, 0);
    return 0;
}
