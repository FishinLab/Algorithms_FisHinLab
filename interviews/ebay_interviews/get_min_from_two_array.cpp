#include <iostream>

using namespace std;

int main(){
    int a[] = {1,2,3,4,5,6};
    int b[] = {7,8,9};
    int minus = a[0] - b[2];
    if(minus > b[0] - a[5]){
        minus = b[0] - a[5];    
    }
    cout << minus << endl;
    return 0;
}
