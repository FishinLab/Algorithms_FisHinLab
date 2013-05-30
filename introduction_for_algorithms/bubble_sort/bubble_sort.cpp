#include <iostream>
#include <vector>

using namespace std;

vector<int>* bubble_sort(vector<int>* src_data, int data_scale)
{
    int i = 0;
    while(i < data_scale)
    {
        int tmp = (*src_data)[i];
        for(int c = i; c < data_scale - 1; ++c)
        {
            if((*src_data)[c] > (*src_data)[c + 1])
            {
                tmp = (*src_data)[c + 1];
            }
        }
        src_data->insert(src_data->begin() + i - 1, tmp);
        i++;
    }
    return src_data;
}

int main(int argc, const char* argv[])
{
    vector<int>* src_data = new vector<int>;
    int data_scale = argc - 1;
    for(int i = 0; i < data_scale; ++i)
    {
        src_data->push_back(atoi(argv[i]));
    }

    vector<int>* res_data = new vector<int>;
    res_data = bubble_sort(src_data, data_scale);

    for(vector<int>::iterator i_r = res_data->begin(); i_r != res_data->end(); ++i_r)
    {
        cout << *i_r;
    }
    cout << endl;
    return 0;
}
