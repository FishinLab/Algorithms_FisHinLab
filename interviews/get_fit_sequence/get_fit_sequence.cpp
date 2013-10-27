#include <iostream>

using namespace std;

void get_sub(int* input_data, int len, int m){
    int* start = input_data;
    int* end = input_data + 1;
    int sum = 0, sum_len;
    while(end != input_data + len - 1){
        if(*end + sum <= m){
            sum += *end;
            end++;
            sum_len++;
        }else if(*end + sum > m){
            start++;
        }else end++;
    }
    start = end - sum_len;
    for(; start != end; start++){
        printf("%d ", *start); 
    }
    printf("\n");
}

int main(int argc, const char* argv[]){
    int* input_data = new int[argc - 1];
    int len = argc - 1;
    for(int i = 1; i < len; ++i) input_data[i - 1] = atoi(argv[i]);
    
    int m;
    scanf("%d", &m);
    get_sub(input_data, len, m);
    return 0; 
}
