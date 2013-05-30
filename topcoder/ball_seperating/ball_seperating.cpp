#include <iostream>
#include <vector>

using namespace std;

int get_move_number(vector<vector<int>* >*);

int main(int argc, const char* argv[])
{
    vector<vector<int>* >* p_src_data = new vector<vector<int>* >;
    int result = get_move_number(p_src_data);
    cout << result << endl;
    return 0;
}

int get_move_number(vector<vector<int>* >* p_src_data)
{
    int result = 0;
    int length = (*p_src_data)[0]->size();
    for(int i = 0; i < length; ++i)
    {
        int tmp = 0;
        if((*(*p_src_data)[0])[i] > (*(*p_src_data)[1])[i])
        {
            tmp = (*(*p_src_data)[0])[i];
            result += (*(*p_src_data)[1])[i]; 
        }
        else 
        {
            tmp = (*(*p_src_data)[1])[i];
            result += (*(*p_src_data)[0])[i];  
        }
        if(tmp > (*(*p_src_data)[2])[i])
        {
            result += (*(*p_src_data)[2])[i]; 
        }
        else
        {
            result += tmp;
        }
    }
    return result;
}

