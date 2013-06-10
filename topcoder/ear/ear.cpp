#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> >::iterator get_uppest(vector<pair<int, int> >*);
pair<int, int> get_loop(vector<int>*, pair<int, int>);
bool if_inside(vector<pair<int, int> >::iterator, pair<int, int>, pair<int, int>);

int main(int argc, const char* argv[])
{
    vector<int>* p_bottom = new vector<int>;
    vector<pair<int, int> >* p_floating = new vector<pair<int, int> >;
    vector<pair<int, int> >::iterator i_uppest = get_uppest(p_floating);
    pair<int, int> outsidest;
    pair<int, int> loop = get_loop(p_bottom, outsidest);
    p_bottom->erase(p_bottom->begin() + loop.first);
    p_bottom->erase(p_bottom->begin() + loop.second);
    int result = 0;
    
    for(vector<pair<int, int> >::iterator i = p_floating->begin(); i != p_floating->end(); ++i)
    { 
        if(i != i_uppest) if_inside(i_uppest, outsidest, *i) ? result += 1 : result;
    }

    cout << result << endl;
    return 0;
}

vector<pair<int, int> >::iterator get_uppest(vector<pair<int, int> >* p_floating)
{
    vector<pair<int, int> >::iterator i_res = p_floating->begin();
    for(vector<pair<int, int> >::iterator i = p_floating->begin(); i != p_floating->end(); ++i)
    { if((*i).second >= (*i_res).second) i_res = i; }
    return i_res;
//FIXME:
//i use surface copy here which i_res = i, because in function main i need the address of the iterator
//maybe this is a wrong idea
}

pair<int, int> get_loop(vector<int>* p_bottom, pair<int, int> loop)
{
    pair<int, int> outsidest;
    int min = *(p_bottom->begin()), max = *(p_bottom->begin());
    for(vector<int>::iterator i = p_bottom->begin(); i != p_bottom->end(); ++i)
    {
        if(min >= *i)
        {
            min = *i;
            loop.first = *i;    
        }
        if(max <= *i)
        {
            max = *i;
            loop.second = *i;
        }
    }
    outsidest.first = min; outsidest.second = max;
    return outsidest;
}

bool if_inside(vector<pair<int, int> >::iterator i_uppest, pair<int, int> outsidest, pair<int, int> floating)
{
    int up_dinstance = ((*i_uppest).first - outsidest.first) ^ 2 + ((*i_uppest).second - outsidest.second) ^ 2;
    int distance = (floating.first - outsidest.first) ^ 2 + floating.second - outsidest.second; 
    return (up_dinstance > distance);
}

