#include <iostream>

using namespace std;

void is_palin(char* str){
    int n = strlen(str);
    bool p[n][n];
    int i, j, l;
    for(i = 0; i < n; ++i){
        p[i][i] = true;
    }
    for(l = 2; l <= n; ++l){
        for(i = 0; i < n - l + 1; ++i){
            j = i + l - 1;
            if(l == 2) p[i][j] = (str[i] == str[j]);
            else 
                p[i][j] = (str[i] == str[j]) && p[i + 1][j - 1];
        }
    }
    return;
}

int main(){
    char* str = new char[1024];

    return 0;
}
