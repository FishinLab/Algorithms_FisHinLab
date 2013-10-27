#include <iostream>
#include <vector>

using namespace std;

int get_plan(vector<int>*);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    int result = get_plan(p_src_data);
    cout << result << endl;
    return 0;
}

int get_plan(vector<int>* p_src_data)
{
    int result = 0;
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
         
    }
    return result;
}
