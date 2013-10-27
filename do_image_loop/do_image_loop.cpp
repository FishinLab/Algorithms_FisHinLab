#include <iostream>

using namespace std;
#define N 8
int main()
{
    int c, loop_num;
    scanf("%d", &loop_num);

    int length = loop_num^2 + 1;
    char* init_data = new char[length];
    for(int i = 0; i < length; ++i){
        if(i % loop_num != 0){
            init_data[i] = '.';
        }else init_data[i] = '*';
    }
    cout << init_data << endl;
    delete[] init_data;
    return 0;
}
