#include <iostream>
#include <string>

using namespace std;

int get_result_number(string);

int main(int argc, const char* argv[])
{
    string p_src_data(argv[1]);
    int result = get_result_number(p_src_data);
    cout << result << endl;
    return 0;
}

int get_result_number(string p_src_data)
{
    int res = 0;
    int length = p_src_data.size();
    int b_num, w_num;
    b_num = 0; w_num = 0;

    for(int i = 0; i < length; ++i) 'w' == p_src_data[i] ? w_num += 1 : b_num += 1;
    if(w_num >= b_num)
    {
        for(int i = 0; i < length; ++i)
        {
            if(0 == i % 2)
            {
                'w' == p_src_data[i] ? res : res += 1;
            }
            else 'b' == p_src_data[i] ? res : res += 1;
        }
    }
    else
    {
        for(int i = 0; i < length; ++i)
        {
            if(0 == i % 2)
            {
                'b' == p_src_data[i] ? res : res += 1;
            }
            else 'w' == p_src_data[i] ? res : res += 1;
        }
    }
    return res;
}
