#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[])
{
    vector<int>* src_data = new vector<int>; 
    for(int i = 1; i < argc - 1; ++i) src_data->push_back(atoi(argv[i]));
    vector<int>::iterator i_src = src_data->begin();
    while(i_src != src_data->end())
    {
        while(*i_src != 1)
        {
            if(0 == (*i_src % 2)) *i_src = (*i_src) / 2;
            else *i_src = (3 * (*i_src)) / 2; 
        }
        cout << *i_src << endl;
        i_src++;
    }
    
}
