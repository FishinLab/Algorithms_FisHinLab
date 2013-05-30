#include <iostream>
#include <vector>

using namespace std;

vector<int>* fork_trangle(vector<int>* down, int level)
{
    if((down->size()) == level)
    {
        return down; 
    }
    else
    {
        vector<int>* up = new vector<int>;
        up->push_back(1);
        up->push_back(1);
        int len = (up->size());
        for(int i = 1; i < len - 1; ++i)
        {
            (*up)[i] = (*down)[i - 1] + (*down)[i];
            cout << (*up)[i] << " ";
        }
        cout << endl;
        up->push_back(1);
        fork_trangle(up, level);
    }
}

int main(int argc, const char* argv[])
{
    int level = atoi(argv[1]);
    vector<int> level_1(1,1);
    vector<int> level_2(2,1);
    vector<int>* down = &level_2;
    vector<int>* up = &level_2;
    vector<int>* result = new vector<int>;
    result = fork_trangle(down, level);
    return 0;
}
