#include <iostream>
#include <vector>

using namespace std;

vector<int>* insertion_sort(vector<int>* src_data, int data_scale)
{
    vector<int>* res_data = new vector<int>;
    for(int i = 0; i < data_scale; ++i)
    {
        for(int j = i; j < data_scale; ++j)
        {
            if(src_data[i] > src_data[j])
            {
                vector<int>::iterator tmp = src_data->begin() + j;
                src_data->insert(tmp, *(src_data->begin() + i)); 
            }
        }
    }
}

int main(int argc, const char* argv[])
{
    
    vector<int>* src_data = new vector<int>;
    int data_scale = sizeof(argv[1]);
    for(int i = 0; i < data_scale; ++i)
    {
        src_data->push_back(argv[1][i]);   
    }

    vector<int>* res_data = new vector<int>;
    res_data = insertion_sort(src_data, data_scale);

    for(vector<int>::iterator i_r = res_data->begin(); i_r != res_data->end(); ++i_r)
    {
        cout << *i_r << " "; 
    }
    return 0;
}
