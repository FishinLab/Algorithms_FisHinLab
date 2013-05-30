#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, const char* argv[])
{
    vector<int> src_data;
    int data_scale = argc - 1;
    for(int i = 1; i < data_scale + 1; ++i)
    {
        src_data.push_back(atoi(argv[i]));
    }
    vector<int>* heap = new vector<int>;
    *(heap->begin()) = *(src_data.begin())
    int c = 1;
    while(c < data_scale)
    {
        c++;  
    }
    return 0;
}
