#include <iostream>

using namespace std;

int main()
{
    int data[6] = {3, 4, -1, 1, 5, 7};
    int i, j, min_index = 0, length = 6, c;
    for(i = 0; i < length; ++i){
        for(j = i + 1; j < length; ++j){
            if(data[j] > data[j - 1]){
                min_index = j - 1;
            } 
        }
        int tmp = data[i];
        data[i] = data[min_index];
        data[min_index] = tmp;
        printf("i : %d\n", i);
        for(c = 0; c < length; ++c) printf("%d ", data[c]);
        printf("\n");
    }
    return 0;
}
