#include <iostream>
#include <vector>

using namespace std;

vector<int>* get_sum(vector<int>*, int);

int main(int argc, const char* argv[])
{
    int data_scale = argc + 1;
    int sum_res = 0;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 0;i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    vector<int>* p_res = get_sum(p_src_data, sum_res);
    for(vector<int>::iterator i_res = p_res->begin(); i_res != p_res->end(); ++i_res)
    {
        cout << *i_res << " ";
    }
    cout << endl << sum_res << endl;
    delete p_src_data, p_res;
    return 0;
}

vector<int>* get_sum(vector<int>* p_src_data, int sum_res)
{
    vector<int>* p_res = new vector<int>;
    int tmp_rec = (*p_src_data)[1]; 
    for(vector<int>::iterator i = p_src_data->begin() + 1; i != p_src_data->end(); ++i)
    {
        if(tmp_rec <= *i)
        {
            sum_res += ((*i) - tmp_rec); 
            tmp_rec = *i;
        }
        else
        {
            tmp_rec = *i;
        }
    }
    return p_res;
}
