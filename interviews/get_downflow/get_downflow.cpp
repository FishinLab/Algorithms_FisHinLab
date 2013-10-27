#include <iostream>

using namespace std;

void binary_sort(int* data, int left, int right){
    if(data == NULL) return;
    int mid = int(left + right) / 2;
    if(left >= right) return mid;
    else if(data[mid] < data[right]){
        binary_sort(data, mid, right);
    }

}

int main(int argc, const char* argv[]){
    int* data = new int[argc - 1];
    for(int i = 1; i < argc; ++i) data[i - 1] = atoi(argv[i]);
    int length = argc - 1;
    for(int i = 1; i < length - 1; ++i){
        if(data[i - 1] >= data[i] && data[i] <= data[i + 1]){
            printf("downflow is : %d\n", data[i]);
        }
    }
    return 0;
}
