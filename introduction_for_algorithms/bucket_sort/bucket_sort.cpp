#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, const char* argv[])
{
    vector<double>* src_data = new vector<double>;
    int data_scale = argc - 1;
    for(int i = 0; i < data_scale + 1; ++i)
    {
        src_data->push_back(atof(argv[i]));
    }
    vector<vector<double> > bucket(10);
    vector<vector<double> >* p_bucket = &bucket;
    vector<double>::iterator i_src = src_data->begin();
    while(i_src != src_data->end())
    {
        for(vector<double>::iterator i_bu = bucket[floor(*i_src) * 10].begin(); i_bu != bucket[floor(*i_src) * 10].end(); ++i_bu)
        {
            if(*i_src > *i_bu)
            {
                bucket[floor((*i_src) * 10)].insert(i_bu + 1, *i_src);
            }
        }
        i_src++;
    }
    delete src_data;
    for(vector<vector<double> >::iterator i = bucket.begin(); i != bucket.end(); ++i)
    {
        for(vector<double>::iterator j = i->begin(); j != i->end(); ++j)
        {
            cout << *j << " ";
        }
    }
    cout << endl;
    return 0;
}
