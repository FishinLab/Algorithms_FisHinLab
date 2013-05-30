#include <iostream>
#include <vector>

using namespace std;

int get_product(vector<int>*);

int main(int argc, const char* argv[])
{
    vector<int>* p_src_data = new vector<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));    
    }
    string result = "";
    //get_product(p_src_data) > 0 ? result = "POSITIVE" : result = "NEGATIVE" ? result = result : result = "ZERO";
    int count = get_product(p_src_data);
    if(0 == count)
        cout << "ZERO" << endl;
    else if(0 < count)
        cout << "POSITIVE" <<endl;
    else
        cout << "NEGATIVE" << endl;
    //cout << result << endl;
    return 0;
}

int get_product(vector<int>* p_src_data)
{
    int count = 0;
    for(vector<int>::iterator p_i = p_src_data->begin(); p_i != p_src_data->end(); ++p_i)
    {
        if( 0 == (*p_i))
        {
            return 0;
        }
        else if( 0 <= (*p_i))
        {
            count++;
        }
    }
    (p_src_data->size() - count) % 2 ? count = -1 : count = 1;
    return count;
}
