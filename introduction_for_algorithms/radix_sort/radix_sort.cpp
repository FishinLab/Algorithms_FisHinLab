#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void radix_sort(vector<int>* src_data, vector<int>* res_data)
{
     
}
int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* src_data = new vector<int>;
    for(int i = 1; i < data_scale; ++i)
    {
        src_data->push_back(atoi(argv[i]));
    }
    vector<int>* res_data = new vector<int>;
    radix_sort(src_data, res_data);
    for(vector<int>::iterator i_r = res_data->begin(); i_r != res_data->end(); ++i_r)
    {
        cout << *i_r << " "; 
    }
    cout << endl;
    return 0;
}
