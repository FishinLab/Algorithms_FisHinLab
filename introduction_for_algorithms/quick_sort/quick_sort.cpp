#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>* p_src_data , int start, int end, int sep) 
{
    int c = 1;
    int limit = end - start + 1;
    int i_begin = *(p_src_data->begin());
    while(c < limit)
    {
        if(i_begin > (*p_src_data)[c])
        {
            int tmp = (*p_src_data)[c];
            p_src_data->erase(p_src_data->begin() + c);
            p_src_data->insert(p_src_data->begin(), tmp); 
            sep = sep + 1;
        }
        c++;
    }
}

vector<int>* quick_sort(vector<int>* p_src_data, int start, int end)
{
    if(start < end)
    {
        int sep = 0;
        partition(p_src_data, start, end, sep);
        quick_sort(p_src_data, start, sep);
        quick_sort(p_src_data, sep, start);
    }
    return p_src_data;
}

int main(int argc, const char* argv[])
{
    vector<int> src_data;
    int data_scale = argc + 1;
    for(int i = 1; i < data_scale + 1; ++i)
    {
        src_data.push_back(atoi(argv[i]));
    }
    vector<int>* p_src_data = &src_data;
    vector<int>* p_res = new vector<int>; 
    p_res = quick_sort(p_src_data, 0, data_scale);
    for(vector<int>::iterator i_p = p_res->begin(); i_p != p_res->end(); ++i_p)
    {
        cout << *i_p << " ";
    }
    cout << endl;
    return 0;
}
