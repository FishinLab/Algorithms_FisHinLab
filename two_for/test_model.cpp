#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#ifndef MAX
#define MAX 10000
#endif

struct v_struct{
    char v_char;
}

int main(int argc, const char* argv[])
{
    vector<vector<v_struct*> >* src_data = new vector<vector<v_struct*> >;
    vector<vector<v_struct*> >* res_data = new vector<vector<v_struct*> >;
    vector<int> v_len; 
    //The Procedure of Inputting Data Ignored
    for(int i = 0; i < MAX; ++i)
    {
        v_len.push_back(sizeof(src_data[i])/sizeof(v_struct));
    }
    
    v_len.sort();
    int max_len = *(v_len.begin()); 
    for(vector<int>::iterator i_v = v_len.begin(); i_v != v_len.end(); ++i_v)
    {
        *i_v = max_len - (*i_v); 
    }

    for(int i = 0; i < MAX; ++i)
    {
        for(int j = 0; j < max_len[i]; ++j)
        {
            int ran = random(seed(clock()));
            int location = floor(ran % max_len[i]);
            (*src_data[i]).push_back(src_data[i][location]);
        }
    }

    for(int i = 0; i < max_len; ++i)
    {
        for(int j = 0; j < MAX; ++j)
        {
            res_data[j][i] = src_data[i][j];            
        }
    }
    return 0;
}
