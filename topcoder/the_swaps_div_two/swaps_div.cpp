#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_diff_num(vector<int>*);
int multi(int);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int> src_data;
    for(int i = 0; i < argc; ++i)
    {
        src_data.push_back(atoi(argv[i]));
    }
    vector<int>* p_src_data = &src_data;
    int diff_num = get_diff_num(p_src_data);
    int result = multi(data_scale) / multi(diff_num);
    cout << result << endl;
    return 0;
}

int multi(int num)
{
    int result = 1;
    while(num > 0)
    {
        result = result * num;
        num--;
    }
    return result;
}

int get_diff_num(vector<int>* p_src_data)
{
    int diff_num = 0;
    map<int, int> summ;
    summ[(*p_src_data->begin())] = 1;
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
        for(map<int, int>::iterator m = summ.begin(); m != summ.end(); ++m)
        {
            if((*m).first == (*i))
            {
                (*m).second += 1;
            }
            else
            {
                summ[*i] = 1;
            }
        }
    }
    for(map<int, int>::iterator m = summ.begin(); m != summ.end(); ++m)
    {
        if((*m).second != 1)
        {
            diff_num += 1;
        }
    }
    return diff_num;
}
