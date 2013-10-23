#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    int* data = new int[argc - 1];
    for(int i = 0; i < argc - 1; ++i){
        data[i] = atoi(argv[i + 1]);
    }
    int i = 0, j = argc - 2;
    while(i <= j){
        printf("%d  %d\n", data[i], data[j]);
        if(!(0 == (data[i] ^ data[j]))){
            printf("this is not palindrome\n");
            break;
        }
        i++;    
        j--;
    }
    printf("this is palindrome\n");
    return 0;
}

