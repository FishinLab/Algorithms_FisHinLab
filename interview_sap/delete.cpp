#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
    vector<char>* src_data = new vector<char>;
    vector<char>* del_data = new vector<char>;
    int tmp_len = sizeof(argv[1]);
    for(int i = 0;i < tmp_len; ++i)
    {
        src_data->push_back(argv[1][i]);
    }
    tmp_len = sizeof(argv[2]);
    for(int i = 0; i < tmp_len; ++i)
    {
        del_data->push_back(argv[2][i]);
    }
    
    for(vector<char>::iterator i_s = src_data->begin(); i_s != src_data->end(); ++i_s)
    {
        for(vector<char>::iterator i_d = del_data->begin(); i_d != del_data->end(); ++i_d)
        {
            if(*i_s == *i_d)
            {
                vector<char>::iterator tmp = i_s;
                if(i_s == src_data->begin())
                {
                    src_data->pop(i_s);
                    i_s = src_data->begin();
                }
                else
                {
                    src_data->pop(i_s);
                    i_s--;
                }
            }
        }
    }
    return 0;
}
