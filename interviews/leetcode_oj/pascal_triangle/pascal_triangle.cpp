#include <iostream>

using namespace std;
int* pascal_triangle(int* pre_tr, int pre_num ){
    int nex_num = pre_num + 1;
    int* nex_tr = new int[nex_num];
    nex_tr[0] = pre_tr[0]; nex_tr[nex_num - 1] = pre_tr[pre_num - 1];
    int c = 1;
    printf("%d ", pre_tr[0]);
    while(c < pre_num){
        nex_tr[c] = pre_tr[c - 1] + pre_tr[c]; 
        printf("%d ", nex_tr[c]); 
        c++;
    }
    printf("%d\n", pre_tr[pre_num - 1]);
    return nex_tr;
}

int main(int argc, const char* argv[]){
    int n = atoi(argv[1]);
    if(1 == n){
        printf("1\n");
    }else if(2 == n){
        printf("1\n");
        printf("1 1\n");
    }else{
        int c = 2;
        int* pre_tr = new int[c];
        pre_tr[0] = 1; pre_tr[1] = 1;
        printf("1\n");
        printf("1 1\n");
        while(c < n){
            int nex_num = c + 1;
            int* nex_tr = new int[nex_num];
            pre_tr = pascal_triangle(pre_tr, c);
            c++;
        }
    }
    return 0;
}
