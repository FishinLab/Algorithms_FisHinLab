#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int>* get_factors(int);
bool check_prime(int);

int main(int argc, const char* argv[])
{
    int init_num = atoi(argv[1]);
    int count = 0;
    if(check_prime(init_num))
    {
        cout << "John" << endl;
    }
    while(false == check_prime(init_num))
    {
        vector<int>* factors = get_factors(init_num);
        init_num = init_num - (*factors)[0];
        cout << init_num << endl;
        count++;
    }
    if(0 == (count % 2))
    {
        cout << "Brus" << endl;
    }
    else cout << "John" << endl;
    return 0;
}

vector<int>* get_factors(int num)
{
    vector<int>* result = new vector<int>;
    int i = 2;
    while(i < num - 1)
    {
        if((check_prime(num)) && (0 == num % i))
        {
            result->push_back(i);
        }
        i++;
    }
    return result;
}

bool check_prime(int num)
{
    int down_limit = ceil(sqrt(num)); 
    int i = 2;
    while(i < down_limit)
    {
        if(num % i)
        {
            return false;
        }
        i++;
    }
    return true;
}
