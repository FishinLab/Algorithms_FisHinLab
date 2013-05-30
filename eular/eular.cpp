#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#ifndef DEF_MAX
#define DEF_MAX 1000000
#endif

static void get_primes(int num, vector<int>* p_primes);
static bool check_prime(int num);
static void get_basic_factors(int num, vector<int>* p_factors);

void get_primes(int num, vector<int>* p_primes)
{
    p_primes->push_back(2);
    for(int i = 3; i < num; ++i)
    {
        if(check_prime(i))
        {
            p_primes->push_back(i);
        }
    }
}

bool check_prime(int num)
{
    int loop_up = ceil(sqrt(num));

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

void get_basic_factors(int num, vector<int>* p_factors)
{
    vector<int>* p_primes = new vector<int>; 
    get_primes(num, p_primes);
    for(vector<int>::iterator i_p = p_primes->begin(); i_p != p_primes->end(); ++i_p)
    {
        if(0 == num % (*i_p))
        {
            p_factors->push_back(*i_p);
        }
    }
}

int main(int argc, const char* argv[])
{
    int num;
    int res = 0;
    argv[1] ? num = atoi(argv[1]) : num = DEF_MAX; 
    vector<int>* p_factors = new vector<int>;
    vector<int>* p_tmp = new vector<int>;
    get_basic_factors(num, p_factors);

    for(int i = 2; i < num; ++i)
    {
        if(check_prime(i) && (0 == num % i))
        {
            res++;
            continue;
        }
        get_basic_factors(i, p_tmp);
        for(vector<int>::iterator i_p = p_tmp->begin(); i_p != p_tmp->end(); ++i_p)
        {
            if(0 == num % (*i_p))
            {
                res++; 
            }
        }
    }
    printf("Eular function returns %d\n", res);
    return 0;
}
