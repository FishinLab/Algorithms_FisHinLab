#include <iostream>
#include <vector>

using namespace std;

bool is_in(int b[], int b_len, int a_data){
    for(int i = 0; i < b_len; ++i){
        if(a_data == b[i]) return true; 
    }
    return false;
}

int main(int argc, const char* argv[]){
    int a[4] = {1, 3, 2, 5};
    int b[2] = {5, 3};
    int a_index = 0, b_index = 0;
    while(a_index < 4){
        if(is_in(b, 2, a[a_index])){
            a[a_index] = b[b_index];
            b_index++;
        }
        a_index++;
    }
    for(int i = 0; i < 4; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
