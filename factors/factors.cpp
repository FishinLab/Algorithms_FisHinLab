#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#ifndef DEFAULT_PARA
#define DEFAULT_PARA 1
#endif

int main(int argc, const char* argv[])
{
    int factor, length;
    int sum = 0;
    argv[1] ? factor = atoi(argv[1]) : factor = DEFAULT_PARA;

    for(int i = 1; i < factor; ++i)
    {
        if(0 == (factor % i))
        {
            sum += i;
            length++;
        }
    }
    printf("factor sum is %d, and the factors number is %d", sum, length)
    return 0;
}
