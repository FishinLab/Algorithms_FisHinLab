#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool check_prime(int num)
{
    int loop_up = ceil(sqrt(num));
    for(int i = 2; i < loop_up; ++i)
    {
        if(0 == (num % i))
        {
            return false;
        }
        else continue;
    }
    return true;
}

int main(int argc, const char* argv[])
{
    int max_limit = atoi(argv[1]);
    printf("%d\n", 2);

    for(int i = 3; i < max_limit; ++i)
    {
        if(check_prime(i))
        {
            printf("%d\n", i);
            i++;
        }
        else continue;
    }
    return 0;
}
