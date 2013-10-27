#include <iostream>

using namespace std;

void find_all_combinations(int* data, int length, int* begin, int total_len){
    if(length < 1) return;    
    else if(length == 1){
        printf("%d ", *data);
        for(int i = 0; i < total_len; ++i){
            printf("%d ", begin[i]); 
        }
        printf("\n");
    }
    else{
        printf("%d ", *data);
        for(int i = 1; i < length; ++i){
            printf("%d ", data[i]);
        }
        for(int i = 0; i < total_len; ++i){
            printf("%d ", begin[i]); 
        }
        printf("\n");
        for(int i = 1; i < length; ++i){
            printf("%d ", data[i]);
        }
        printf("%d ", *data);
        for(int i = 0; i < total_len; ++i){
            printf("%d ", begin[i]); 
        }
        printf("\n");
        length--;
        data = data + 1;
        total_len++;
        find_all_combinations(data, length, begin, total_len);
    }
}

int main(int argc, const char* argv[]){
    int length = argc - 1;
    int* data = new int[length];
    for(int i = 0; i < length; ++i) data[i] = atoi(argv[i + 1]);

    find_all_combinations(data, length, data, 0);
    return 0;
}
