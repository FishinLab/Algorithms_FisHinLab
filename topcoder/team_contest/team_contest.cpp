#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using namespace std;

int get_strength(vector<int>*);
int get_worst_rank(vector<int>*, int);

int main(int argc, const char* argv[])
{
    int data_scale = argc + 1;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 0; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    vector<int>* p_my_team = new vector<int>;
    vector<int>* p_others = new vector<int>;
    for(int i = 0; i < 2; ++i)
    {
        p_my_team->push_back((*p_src_data)[i]);
    }
    for(int i = 3; i < data_scale + 1; ++i)
    {
        p_others->push_back((*p_src_data)[i]);
    }
    int strength = get_strength(p_my_team);
    int worst_rank = get_worst_rank(p_others, strength);
    cout << worst_rank << endl;
    delete p_src_data, p_my_team;
    return 0;
}

int get_strength(vector<int>* p_my_team)
{
    int strength = max(max((*p_my_team)[0], (*p_my_team)[1]), (*p_my_team)[2])
                   + 
                   min(min((*p_my_team)[0], (*p_my_team)[1]), (*p_my_team)[2]); 
    return strength;
}

int get_worst_rank(vector<int>* p_others, int strength)
{
    list<int>* tmp_list = new list<int>;
    int worst_rank = 0;
    int limit = p_others->size();
    for(vector<int>::iterator i_vec = p_others->begin(); i_vec != p_others->end(); ++i_vec)
    {
        tmp_list->push_back(*i_vec);
    }
    tmp_list->sort(greater<int>());
    vector<int>* tmp_vector = new vector<int>;
    for(list<int>::iterator i_list = tmp_list->begin(); i_list != tmp_list->end(); ++i_list)
    {
        tmp_vector->push_back(*i_list);
    }
    delete tmp_list;
    int i = 2;
    while(i < limit)
    {
        int tmp = (*tmp_vector)[0] + (*tmp_vector)[1] + (*tmp_vector)[i]; 
        if(tmp >= strength)
        {
            worst_rank++;
        }
        i++;
    }
    delete p_others;
    return worst_rank;
}
