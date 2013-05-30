#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#ifndef SMALL
#define SMALL 0.001
#endif

int main(int argc, const char* argv[])
{
    const char* arr = argv[1];
    int length = strlen(arr);
    string check_num(arr);
    int num = 0;

    for(int i = 0; i < length; ++i)
    {
        num += (int)arr[i] - (int)('0'); 
    }
    cout << num << endl;
    if(SMALL <= (num / 9))
    {
        printf("%d could not be divided by 9\n", atoi(arr));
        return 0;
    }
    else printf("%d could be divided by 9\n", atoi(arr));
    return 0;
}
