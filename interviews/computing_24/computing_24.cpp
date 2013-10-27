#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define result  24

int op(int a, int b, int type)
{
    if(0 == type) return a + b;
    else if(1 == type) return a - b;
    else if(2 == type) return a * b;
    else return a/b;
}

void rotate_data(int* input_data, int length)
{
    int dst_data[length];
    dst_data[length - 1] = input_data[0];
    for(int i = 0; i < length - 1; ++i) dst_data[i + 1] = input_data[i];
    int* tmp = input_data;
    input_data = dst_data;
    delete[] tmp;
}

bool op(int* input_data, int length)
{
    int res = 0;
    for(int i = 0; i < length - 1; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            int tmp = res;
            res = op(input_data[i], input_data[i + 1], j); 
            if(res < 0) res = tmp;
        }
        if(result == res) return true;
        rotate_data(input_data, length); 
    }
    return false;
}

int main(int argc, const char* argv[])
{
    int input_data[4];
    int length = sizeof(input_data);
    while(true)
    {
        int length = sizeof(input_data);
        bool flag = op(input_data, length);
        break;
    }
    for(int i = 0; i < length; ++i) cout << input_data[i] << endl;
    return 0;
}
