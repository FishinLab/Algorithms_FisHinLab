#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, const char* argv[])
{
    vector<int>* src_data = new vector<int>;
    int data_scale = argc - 1;
    for(int i = 1;i < argc; ++i)
    {
        src_data->push_back(atoi(argv[i]));
    }
    int min = (*src_data)[0];
    int max = (*src_data)[0];
    vector<int>::iterator i_p = src_data->begin();
    while(i_p != src_data->end())
    {
        if(*i_p > max)
        {
            max = *i_p;
        }
        if(*i_p < min)
        {
            min = *i_p;
        }
        i_p++;
    }
    cout << "max: " << max << " min: " << min << endl;
    delete src_data;
    return 0;
}
