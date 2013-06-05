#include <iostream>
#include <vector>

using namespace std;

int get_demage(vector<int>*, vector<int>*);
int get_sum(vector<int>::iterator, vector<int>::iterator);

int main(int argc, const char* argv[])
{
    vector<int>* p_bps = new vector<int>;
    vector<int>* p_hp = new vector<int>;
    int result = get_demage(p_bps, p_hp);
    cout << result << endl;
    return 0;
}

int get_demage(vector<int>* p_bps, vector<int>* p_hp)
{
    int result = 0;
    int i = 0;
    int length = p_bps->size();
    while(i < length)
    {
        result += (*p_hp)[i] * (get_sum(p_bps->begin() + i, p_bps->end()));
        i++;
    }
    return result;
}

int get_sum(vector<int>::iterator i_start, vector<int>::iterator i_end)
{
    int result = 0;
    vector<int>::iterator i = i_start;
    while(i != i_end)
    {
        result += (*i);
        i++;
    }
    return result;
}
