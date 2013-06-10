#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int>* get_sequence(vector<int>*, int);
vector<int>* get_new_seq(vector<int>*);

int main(int argc, const char* argv[])
{
    int number = 0;
    argv[1] ? number = atoi(argv[1]) : number;
    vector<int>* p_data = new vector<int>;
    p_data->push_back(1);
    p_data->push_back(1);
    get_sequence(p_data, number);
    for(vector<int>::iterator i = p_data->begin(); i != p_data->end(); ++i) {cout << *i << " ";}
    cout << endl;
    return 0;
}

vector<int>* get_sequence(vector<int>* p_pre, int num)
{
    while(1 != num)
    {
        vector<int>* p_tmp = get_new_seq(p_pre);
        for(vector<int>::iterator i_p = p_tmp->begin(); i_p != p_tmp->end(); ++i_p){p_pre->push_back(*i_p);};
        num--;
        p_pre = get_sequence(p_pre, num);
    }
    return p_pre;
}

vector<int>* get_new_seq(vector<int>* p_pre)
{
    vector<int>* p_res = new vector<int>; 
    map<int, int>* p_map = new map<int, int>; 
    int length = p_pre->size();

    for(int i = 0; i < *(p_pre->end()); ++i) {(*p_map)[i] = 0;}
    for(int i = 0; i < length; ++i) {(*p_map)[((*p_pre)[i])]++;} 
    for(map<int, int>::iterator i_m = p_map->begin(); i_m != p_map->end(); ++i_m)
    {
        p_res->push_back((*i_m).second);
        p_res->push_back((*i_m).first);
    }
    delete p_map;
    return p_res;
}
