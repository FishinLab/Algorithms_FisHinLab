#include <iostream>
#include <vector>
#include <set>

using namespace std;

int fomular_or(vector<int>*);
int get_sum(vector<int>*);
int get_distinct_or(vector<int>*);
void get_subset(vector<int>*, vector<int>*, vector<int>::iterator, vector<int>::iterator, vector<vector<int>* >*, int);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    int result = get_distinct_or(p_src_data);
    cout << result << endl;
    return 0;
}

int get_distinct_or(vector<int>* p_data)
{
    set<int> p_set;
    vector<vector<int>* >* p_res = new vector<vector<int>* >;
    vector<int>* p_cur = new vector<int>;
    vector<int>::iterator i_start = p_data->begin(), i_end = p_data->begin();
    //get_subset(p_data, p_cur, p_data->begin(), p_data->begin(), p_res, 0);
    get_subset(p_data, p_cur, i_start, i_end, p_res, 0);

    for(vector<vector<int>* >::iterator i = p_res->begin(); i != p_res->end(); ++i)
    {
        int or_tmp = fomular_or(*i);
        if(*(p_set.find(or_tmp))){} else p_set.insert(p_set.begin(), or_tmp);
        if((2 ^ ((*i)->size())) == p_set.size())
        {
            return get_sum(*i);
        }
    }
    return 0; 
}

void get_subset(vector<int>* p_set, vector<int>* p_cursor, vector<int>::iterator i_start, vector<int>::iterator i_end, vector<vector<int>* >* p_res, int length)
{
    if((i_start != p_set->end()) || (i_end != p_set->end()) || (i_start != i_end))
    {
        for(int i = 0; i < length; ++i)
        {
            p_cursor->push_back(*(i_start + i));
        }
        p_res->push_back(p_cursor);
        //DEBUG:
        for(vector<int>::iterator x = p_cursor->begin(); x != p_cursor->end(); ++x)
        {
            cout << *x << " ";
        }
        cout << endl;
        p_cursor->clear();
        if(i_end != p_set->end()) 
        {
            i_end++;length++;
            get_subset(p_set, p_cursor, i_start, i_end, p_res, length);
        }
        else 
        {
            i_start++;length--;
            get_subset(p_set, p_cursor, i_start, i_end, p_res, length);
        }
    }
    return; 
}

int get_sum(vector<int>* p_vec)
{
    int result = 0;
    for(vector<int>::iterator p = p_vec->begin(); p != p_vec->end(); ++p)
    {
        result += *p; 
    }
    return result;
}

int fomular_or(vector<int>* p_vec)
{
    int result = 0;
    for(vector<int>::iterator p = p_vec->begin(); p != p_vec->end(); ++p)
    {
        result = result | (*p); 
    }
    return result;
}
