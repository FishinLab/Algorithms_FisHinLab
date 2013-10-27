#include <iostream>

using namespace std;

int binary(int* data, int left, int right){
    if(NULL == data) return -1;
    int mid = (left + right) / 2;
    if(data[mid] < data[left] && data[mid] < data[right]){
        return mid; 
    }else{
        binary(data, left, mid);
        binary(data, mid + 1, right);
    } 
}

int binary_search(int* data, int left, int right, int x){
    if(NULL == data) return -1;
    int mid = (left + right) / 2;
    if(data[mid] < x){
        binary_search(data, mid, right, x);
    }else if(data[mid] > x){
        binary_search(data, left, mid, x); 
    }else if(data[mid] == x){
        return data[mid];
    }else return -1;
}

int main(int argc, const char* argv[]){
    int* data = new int[argc - 1];
    for(int i = 1;i < argc - 1; ++i) data[i - 1] = atoi(argv[i]);
    int length = argc - 1;
    int min = binary(data, 0, length);
    printf("min is %d\n", min);
    int* sorted_data = new int[argc - 1];
    int x = 0;
    for(int i = min + 1; i != min; i = i % (length)){
        sorted_data[x] = data[i];
        x++;
    }
    scanf("%d", &x);
    if(sorted_data[0] > x || sorted_data[argc - 1] < x) printf("%d\n", -1);
    else{
        int res = binary_search(sorted_data, 0, length, x);
        printf("result is %d\n", res);
    } 

    delete[] data;
    delete[] sorted_data;
    return 0;
}
