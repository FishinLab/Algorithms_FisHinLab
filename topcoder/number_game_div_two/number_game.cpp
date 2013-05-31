#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int get_max_factor(int);
bool check_prime(int);

int main(int argc, const char* argv[])
{
    int src_data = atoi(argv[1]);
    int count = 0;
    do 
    {
        count++;
        if(!check_prime(src_data))
        {
            int b_f = get_max_factor(src_data);
            src_data = src_data - b_f;
        }
        else
        {
            break;
        }
    }while(true);
    string winner = "";
    count % 2 == 0 ? winner = "B" : winner = "A";
    cout << winner << endl;
    return 0;
}

bool check_prime(int src_data)
{
    int limit_up = ceil(sqrt(src_data));
    for(int i = 2; i <= limit_up; ++i)
    {
        if(0 == (src_data % i))
        {
            return false;
        }
    }
    return true;
}

int get_max_factor(int src_data)
{
    int limit_down = floor(sqrt(src_data));
    vector<int> factors;
    for(int i = limit_down; i < src_data; ++i)
    {
        if(0 == src_data % i) 
        {
            factors.push_back(i);
        }
    }
    return *(factors.end());
}
