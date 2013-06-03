#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool check_even_odd(int);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    int result = 0;
    int even_res = 0;
    int odd_res = 0;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
        check_even_odd(*i) ? even_res += *i : odd_res += *i;
    }
    even_res >= odd_res ? result = even_res : result = odd_res; 
    cout << result << endl;
    return 0;
}

bool check_even_odd(int data)
{
    bool result;        
    0 == (data % 2) ? result = true : result = false;
    return result;
}
