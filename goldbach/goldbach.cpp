#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#ifndef DEF_MAX
#define DEF_MAX 1000000
#endif

bool check_prime(int num)
{
    int loop_up = ceil(sqrt(num) + 1);
    for(int i = 2; i <= loop_up; ++i)
    {
        if(0 == (num % i))
        {
            return false;
        }
        else continue;
    }
   
    return true;
}

void get_prime(int num, vector<int>* v_primes)
{
    v_primes->push_back(2);
    for(int i = 3; i < num; ++i)
    {
        if(check_prime(i))
        {
            v_primes->push_back(i);
            i++;
        }
        else continue;
    }
}

int main(int argc, const char* argv[])
{
    int num;
    argv[1] ? num = atoi(argv[1]) : num = DEF_MAX;
    vector<int>* v_primes = new vector<int>;
    get_prime(num, v_primes);

    for(vector<int>::iterator i_p = v_primes->begin(); i_p != v_primes->end(); ++i_p)
    {
        if(check_prime(num - (*i_p)))
        {
            printf("%d == %d + %d\n", num, *i_p, (num - (*i_p)));
        }
    }
    return 0;
}
