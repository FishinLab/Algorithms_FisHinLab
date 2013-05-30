#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void merge(vector<int>* v_data_a, vector<int>* v_data_b)
{

}

vector<int>* merge_sort(vector<int>* src_data, int start, int end)
{

}

int main(int argc, const char* argv[])
{
    vector<int>* src_data = new vector<int>;
    int data_scale = argc;
    for(int i = 0; i < data_scale; ++i)
    {
        src_data->push_back(atoi(argv[i]));
    }
    return 0;
}
