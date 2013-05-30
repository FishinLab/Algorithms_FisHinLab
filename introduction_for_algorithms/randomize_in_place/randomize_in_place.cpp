#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, const char* argv[])
{
    vector<int>* src_data = new vector<int>;
    vector<int>* res_data = new vector<int>;
    int data_scale = argc - 1;
    for(int i = 1; i < data_scale + 1; ++i)
    {
        src_data->push_back(atoi(argv[i]));
    }
//DEBUG
//    for(vector<int>::iterator i_tmp = src_data.begin(); i_tmp != src_data.end(); ++i_tmp)
//        {
//            cout << *i_tmp << endl;
//        }

    //srand(time(0));
    //int ran = rand();
     
    int i = 0;
    while(i < data_scale)
    {
        srand(time(0));
        int tmp_ran = rand();
        int location = floor(tmp_ran % (data_scale - 1));
        res_data->push_back((*src_data)[location]);
        src_data->erase(src_data->begin() + location);
        i++;
    }
    for(vector<int>::iterator i_r = res_data->begin(); i_r != res_data->end(); ++i_r)
    {
        cout << *i_r << " ";
    }
    cout << endl;
    
    return 0;
}
