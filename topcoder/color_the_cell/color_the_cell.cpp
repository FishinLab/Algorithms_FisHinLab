#include <iostream>
#include <vector>

using namespace std;

int get_max(vector<int>*);
void paint_and_move(vector<int>* , int, int);

int main(int argc, const char* argv[])
{
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    int time_duration = 0;
    int max_pos = get_max(p_src_data);
    cout << &time_duration << endl; 
    paint_and_move(p_src_data, max_pos, &time_duration); 
    cout << time_duration << endl;
    delete p_src_data;
    return 0;
}

int get_max(vector<int>* p_src_data)
{
    int res = (*p_src_data)[0]; 
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i) *i >= res ? res = *i : res;
    return res;
}

void paint_and_move(vector<int>* p_src_data, int max_pos, int time_duration)
{
    int length = p_src_data->size();
    int curr_pos = 1;
    cout << &time_duration << endl;
    do 
    {
        if(curr_pos == max_pos)
        {
            curr_pos++;
            time_duration++;
        }
        else if(curr_pos != max_pos)
        {
            time_duration += (*p_src_data)[curr_pos - 1];
            length--;
            curr_pos++;
        }
        else break;
    }while(length > 0);
}
