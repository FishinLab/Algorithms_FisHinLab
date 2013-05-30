#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<int> src_data;
    for(int i = 1; i < data_scale + 1; ++i)
    {
        src_data.push_back(atoi(argv[i]));
    }
    vector<int> result(data_scale);
    vector<int> tmp;
    int c = 0;
    while(c < data_scale)
    {
        int count = 0;
        for(int i = 0; i < data_scale; ++i)
        {
            if(src_data[c] > src_data[i])
            {
                count = count + 1;
            }
        }
        *(result.begin() + count) = src_data[c];
        c ++;
    }
    for(vector<int>::iterator i_r = result.begin(); i_r != result.end(); ++i_r)
    {
        cout << *i_r << " ";
    }
    cout << endl;
    //vector<int>* result = new vector<int>;
    return 0;
}
