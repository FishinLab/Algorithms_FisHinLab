#include <iostream>

using namespace std;

void output_array(int* data, int length){
    int* buf = new int[length - 1];
    int buf_len = 0, c = 0;
    while(c  < length){
        if(data[c] % 2){
            printf("%d ", data[c]);  
        }else{
            buf[buf_len] = data[c];
            buf_len++;
        } 
        c++;
    }
    for(int i = 0; i < buf_len; ++i){
        printf("%d ", buf[i]);  
    }
    printf("\n");
}

int main(int argc, const char* argv[]){
    int* data = new int[argc - 1];
    for(int i = 0; i < argc - 1; ++i){
        data[i] = atoi(argv[i + 1]);
    }
    output_array(data, argc - 1);
    return 0;
}
