#include <iostream>
#include <vector>

using namespace std;

vector<int>* reverse_sort(vector<int>* src_data, int data_scale)
{
    vector<int>* res_data = new vector<int>;
    for(vector<int>::iterator i_s = data_scale->begin(); i_s != data_scale->end(); ++i_s)
    {
        res_data->push_back(*i_tmp);
        vector<int>::iterator i_tmp = i_s;
        if(*(i_s) > *(i_s + 1))
        {
            i_tmp = i_s + 1; 
        }
    }
}

int main(int argc, const char* argv[])
{
    vector<int>* src_data = new vector<int>;
    vector<int>* res_data = new vector<int>;
    int data_scale = sizeof(argv[1]);
    for(int i = 0; i < data_scale; ++i)
    {
        src_data->push_back(argv[1][i]);
    }

    res_data = reverse_sort(src_data, data_scale);
    for(vector<int>::iterator i_r = res_data->begin(); i_r != res_data->end(); ++i_r)
    {
        cout << *i_r << " "
    }
    cout << endl;
    return 0;
}
