#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int relocate_jedi(vector<int>*, int);
bool if_end(vector<int>*, int);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < data_scale; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    int kilo = atoi(argv[data_scale]);
    int result = relocate_jedi(p_src_data, kilo);
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
        cout << *i << "  ";
    }
    cout << endl << result << endl;
    return 0;
}

int relocate_jedi(vector<int>* p_src_data, int kilo)
{
    bool flag = false;
    do
    {
        for(vector<int>::iterator p = p_src_data->begin(); p != p_src_data->end(); ++p)
        {
            if((*p) > kilo)
            {
                (*p) = (*p) - 1;
                if(p_src_data->begin() == p)
                {
                    *(p + 1) = *(p + 1) + 1;
                }
                else if(p_src_data->end() == p)
                {
                    *(p - 1) = *(p - 1) + 1;
                }
                else
                {
                    (*(p - 1)) < kilo ? (*(p - 1))++ : (*(p + 1))++; 
                }
            }
        }
        //sort(p_src_data->begin(), p_src_data->end());
        flag = if_end(p_src_data, kilo);
    }while(!flag);
    return (p_src_data->size());
}

bool if_end(vector<int>* p_src_data, int kilo)
{
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
        if(*i > kilo)
        {
            return false;
        }
    }
    return true;
}
