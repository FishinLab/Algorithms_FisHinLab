#include <iostream>

using namespace std;

int main()
{
    int data[] = {};
    int length = sizeof(data) / sizeof(int);
    int i;
    printf("source data is : ");
    for(int c = 0; c < length; ++c) printf("%d ", data[c]);
    printf("\n\n");
    for(i = 0; i < length; ++i){
        if(data[i] >= 0){
            if(data[ data[i] ] > data[i]){
                int tmp = data[data[i]];
                data[ data[i] ] = data[i];
                data[i] = tmp;
            }
        for(int c = 0; c < length; ++c) printf("%d ", data[c]);
        printf("\n");
        } 
    }

    for(int i = 0; i < length; ++i){
        if(data[i] != i){
            printf("result is : %d\n", i);
            return 0;
        }
    }
    printf("result is : %d\n", i + 1);
    return 0;
}
