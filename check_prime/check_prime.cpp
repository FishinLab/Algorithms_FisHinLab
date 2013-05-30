#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, const char* argv[])
{
    int num = atoi(argv[1]);
    int loop_up = ceil(sqrt(num));

    for(int i = 2; i <= loop_up; ++i)
    {
        if(0 == (num % i))
        {
            printf("%d is not a prime\n", num);
            return 0;
        }
        else continue;
    }
   
    printf("%d is a prime\n", num);
    return 0;
}
