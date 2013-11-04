#include <iostream>

using namespace std;
void pascal_triangle(int* pre_tr, int pre_num , int c, int n){
    if(c == n){
        for(int i = 0; i < pre_num; ++i) printf("%d ", pre_tr[i]);
        printf("\n");
        return;
    }
    int nex_num = pre_num + 1;
    int* nex_tr = new int[nex_num];
    nex_tr[0] = pre_tr[0]; nex_tr[nex_num - 1] = pre_tr[pre_num - 1];
    for(int i = 1; i < pre_num; ++i){
        nex_tr[i] = pre_tr[i - 1] + pre_tr[i]; 
    }
    c++;
    pascal_triangle(nex_tr, nex_num, c, n);
}

int main(int argc, const char* argv[]){
    int n = atoi(argv[1]);
    if(1 == n){
        printf("1\n");
    }else if(2 == n){
        printf("1 1\n");
    }else{
        int c = 2;
        int* pre_tr = new int[c]; 
        pre_tr[0] = 1;
        pre_tr[1] = 1;
        pascal_triangle(pre_tr, c, c, n);
    }
    return 0;
}
