#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char* argv[]){
    int data_one[5] = {1,2,3,4,5};
    int data_two[3] = {-1, 0 ,1};
    int result = 0;
    /*
    for(int i = 0; i < 3; ++i){
        if(data_two[i] > 0){
            for(int j = 0; j < 5; ++j){
                if(data_one[j] ^ data_two[i] > data_two[i] ^ data_one[j]) result++;
            }
        } 
        else if(0 == data_two[i]){
            result++;
        }else result++;
    }
    */
    for(int i = 0; i < 3; ++i){
        if(0 >= data_two[i]) result++;
        else continue; 
    }
    printf("The result is %d\n", result);
    return 0;
}
