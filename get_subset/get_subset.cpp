#include <iostream>
#include <map>
#include <vector>

using namespace std;

void get_subset(vector<int>*, vector<int>*, vector<int>::iterator, vector<int>::iterator, int);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    vector<int>* p_cur = new vector<int>;
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
        cout << *i << endl;
        vector<int>::iterator i_start = p_src_data->begin(), i_end = p_src_data->begin();
        get_subset(p_src_data, p_cur, i_start, i_end, 0);
    }
    delete p_src_data,p_cur;
    return 0; 
}

void get_subset(vector<int>* p_src_data, vector<int>* p_cur, vector<int>::iterator i_start, vector<int>::iterator i_end, int length)
{
    if((i_start != p_src_data->end()) || (i_end != p_src_data->end()) || (i_start != i_end))
    {
        for(int i = 0; i < length; ++i)
        {
            cout << *(i_start + 1) << " ";
        }
        cout << endl;
        if(i_end != p_src_data->end()) 
        {
            i_end++;length++;
            get_subset(p_src_data, p_cur, i_start, i_end, length);
        }
        else 
        {
            i_start++;length--;
            get_subset(p_src_data, p_cur, i_start, i_end, length);
        }
    }
    return;
}
