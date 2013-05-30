#include <iostream>
#include <vector>

using namespace std;

#ifndef TEN
#define TEN 10
#endif

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        src_data->push_back(atoi(argv[i]));
    }
    vector<pair<double, int> >* result = new vector<pair<double, int> >;
    double c = 0.0;
    for(int i = 0; i < TEN; ++i)
    {
        pair<double, int> p_tmp;
        p_tmp.first = c + i * 0.1;
        p_tmp.second = 0;
        result->push_back(p_tmp);
    }
    for(vector<int>::iterator i_src = src_data->begin(); i_src != src_data->end(); ++i_src)
    {
        ((*result)[(*i_src) % TEN]).second++;
    }

    for(vector<pair<double, int> >::iterator i_res = result->begin(); i_res != result->end(); ++i_res)
    {
        if(0 != (*i_res).second)
        {
            cout << ((*i_res).first) * TEN << " : " << (*i_res).second << endl;
        }
    }
    return 0;
}
