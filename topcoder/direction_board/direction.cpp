#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class position
{
    public:
        int r;
        int c;
};

int travel(vector<vector<char>* >*, position*);
bool check_loop(vector<vector<char>* >*, position*);
bool check_distance(int, vector<vector<char>* >*);

int main(int argc, const char* argv[])
{
    vector<vector<char>* >* p_src_data = new vector<vector<char>* >;
    position* p_start = new position;
    p_start->r = 0;
    p_start->c = 0;
    if(check_loop(p_src_data, p_start))
    {
        return 0;
    }
    int result = travel(p_src_data, p_start);
    result > 3 ? result = 3 : result = result ; 
    cout << result << endl;
    return 0;
}

int travel(vector<vector<char>* >* p_src_data, position* p_start)
{
    int result = 0;
    int v_bond = p_src_data->size();
    int h_bond = (*p_src_data)[0]->size();
    int bond = v_bond * h_bond;
    position* curr_pos = new position; 
    int moved_steps = 0;

    do{
        if('d' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->r++;
            check_distance(moved_steps, p_src_data) ? result = result + 1 : result = result ;
        }
        else if('u' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->r--; 
        }
        else if('r' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->c++; 
            check_distance(moved_steps, p_src_data) ? result = result + 1 : result = result ;
        }
        else if('l' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->c--;
        }
        moved_steps++;
    }while(curr_pos->c != p_start->c && curr_pos->r != p_start->r && curr_pos->c < v_bond && curr_pos->r < h_bond);
    return result;
}

bool check_distance(int moved_steps, vector<vector<char>* >* p_src_data)
{
    int v_bond = p_src_data->size();
    int h_bond = (*p_src_data)[0]->size();
    bool result = false;
    moved_steps > max(v_bond, h_bond) ? result = true : result = false;
    return result;
}

bool check_loop(vector<vector<char>* >* p_src_data, position* p_start)
{
    bool result = false;
    int v_bond = p_src_data->size();
    int h_bond = (*p_src_data)[0]->size();
    int bond = v_bond * h_bond;
    int count = 0;
    position* curr_pos = p_start;  
    do{
        if(curr_pos->c == p_start->c && curr_pos->r == p_start->r)
        {
            return true;
        }
        else if('d' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->r++;
        }
        else if('u' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->r--; 
        }
        else if('r' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->c++; 
        }
        else if('l' == (*(*p_src_data)[curr_pos->r])[curr_pos->c])
        {
            curr_pos->c--;
        }
    }while(curr_pos->c != p_start->c && curr_pos->r != p_start->r && curr_pos->c < v_bond && curr_pos->r < h_bond && count < bond);
    return false;
}

