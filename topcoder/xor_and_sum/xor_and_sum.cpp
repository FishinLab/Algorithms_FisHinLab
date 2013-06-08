#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int xor_and_sum(vector<int>*);
int get_one(int);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    int result = xor_and_sum(p_src_data);
    cout << result << endl;
    return 0;
}

int xor_and_sum(vector<int>* p_src_data)
{
    int result = 0;
    int length = p_src_data->size();
    map<int, int>* one_num = new map<int, int>;
    for(vector<int>::iterator i_data = p_src_data->begin(); i_data != p_src_data->end(); ++i_data)
    {
        (*one_num)[(*i_data)] = get_one(*i_data);
    }
    map<int, int>::iterator i_m = one_num->begin();
    //int tmp_min = i_m.second, tmp_max = i_m.second;
    pair<int, int> tmp_min = *i_m, tmp_max = *i_m;
    while(i_m != one_num->end())
    {
        i_m++;
        tmp_min.second < (*i_m).second ? tmp_min = *i_m : tmp_min;
        tmp_max.second > (*i_m).second ? tmp_max = *i_m : tmp_max;
    }
    //tmp_min.first = xor((tmp_min.first), (tmp_max.first)); 
    tmp_min.first = (tmp_min.first) ^ (tmp_max.first);
    for(map<int, int>::iterator i = one_num->begin(); i != one_num->end(); ++i)
    {
        result += (*i).first;
    }
    return result;
}

int get_one(int data)
{
    int one = 0;
    while(0 == (int)data / 2) 
    {
        data = data / 2;
        one++;  
    }
    return one;
}
