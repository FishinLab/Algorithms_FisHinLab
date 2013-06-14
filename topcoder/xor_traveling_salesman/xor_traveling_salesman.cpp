#include <iostream>
#include <vector>

using namespace std;

struct pos
{
    pair<int, int> p;
    int data;
    bool traveled;
};

int traveling(vector<vector<pos>* >*);

int main(int argc, const char* argv[])
{
    vector<vector<pos>* >* p_map = new vector<vector<pos>* >;
    int result = traveling(p_map);
    cout << result << endl;
    return 0;
}

int traveling(vector<vector<pos>* >* p_map)
{
    int result = (*(*p_map)[0])[0].data; 
    pair<int, int> p_pos(0, 0);
    pair<int, int> p_next(0, 0);
    
    do
    {
        p_next = (*(*p_map)[p_pos.first])[p_pos.second].p; 
        result <= (*(*p_map)[p_pos.first])[p_pos.second].data ^ result ? result = (*(*p_map)[p_pos.first])[p_pos.second].data ^ result : result;
        (*(*p_map)[p_pos.first])[p_pos.second].traveled = true;
        p_pos = p_next;
    }while(0 != (*(*p_map)[p_pos.first])[p_pos.second].data);
    return result;
}
