#include <iostream>
#include <vector>
#include <math.h>
#include <list>
#include <map>

using namespace std;

int get_post_number(vector<pair<int, int> >*);
vector<pair<int, int> >* parse_data(vector<int>*);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* p_src_data = new vector<int>;
    vector<pair<int, int> >* p_parsed_data = new vector<pair<int, int> >;
    for(int i = 0; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i])); 
    }
    p_parsed_data = parse_data(p_src_data);
    int result = get_post_number(p_parsed_data); 
    cout << result << endl;
    return 0;
}

int get_post_number(vector<pair<int, int> >* p_parsed_data)
{
    int result = 0;
    vector<pair<int, int> >::iterator i = p_parsed_data->begin();
    do
    {
        map<int, int> m_tmp;
        m_tmp[(*i).first] = m_tmp[(*i).first] + 1;
        int tmp = (*i).second - (*i).first;
        for(int t = tmp; t > 0; --t)
        {
            m_tmp[(*i).first + t] = m_tmp[(*i).first + t] + 1;
            if(m_tmp[(*i).first + t] > 1)
            {
                result++;
            }
        }
        i++;
    }while(i != p_parsed_data->end());
    return result;
}

vector<pair<int, int> >* parse_data(vector<int>* p_src_data)
{
    vector<pair<int, int> >* p_parsed_data = new vector<pair<int, int> >;
    vector<int>::iterator p = p_src_data->begin();
    while(p != p_src_data->end())
    {
        pair<int, int> tmp;
        tmp.first = floor((double)(*p) / 10000);
        tmp.second = (*p) - tmp.first; 
        p_parsed_data->push_back(tmp);
        p++;
    }
    return p_parsed_data;
}

