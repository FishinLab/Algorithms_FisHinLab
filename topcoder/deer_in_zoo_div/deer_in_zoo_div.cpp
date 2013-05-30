#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> >* get_diff(vector<int>*, vector<int>*);
int get_isomophic(vector<pair<int, int> >*);

int main(int argc, const char* argv[])
{
    vector<int> graph_1{0, 1, 2};
    vector<int> graph_2{1, 2, 3};
    vector<int>* p_graph_1 = &graph_1;
    vector<int>* p_graph_2 = &graph_2;
    
    vector<pair<int, int> >* p_diff = get_diff(p_graph_1, p_graph_2);
    int result = get_isomophic(p_diff);
    
    cout << result << endl;
    delete p_graph_1, p_graph_2, p_diff;
    return 0;
}

vector<pair<int, int> >* get_diff(vector<int>* p_graph_1, vector<int>* p_graph_2)
{
    vector<pair<int, int> >* result = new vector<pair<int, int> >;
    for(vector<int>::iterator i = p_graph_1->begin(); i != p_graph_1->end(); ++i)
    {
        for(vector<int>::iterator j = p_graph_2->begin(); j != p_graph_2->end(); ++j)
        {
            if(*i != *j)
            {
                pair<int, int> tmp;
                tmp.first = *i;
                tmp.second = *j;
                result->push_back(tmp);
            }
        }
    }
    return result;
}

int get_isomophic(vector<pair<int, int> >* p_diff)
{
    int result = -1;
    vector<pair<int, int> >::iterator tmp = p_diff->begin();
    while(tmp != p_diff->end())
    {
        tmp++;
    }
    return result;
}
