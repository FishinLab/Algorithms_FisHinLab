#include <iostream>
#include <vector>

using namespace std;

int pasting(vector<vector<char>* >*, int);
int get_paste_b(vector<vector<char>* >*);

int main(int argc, const char* argv[])
{
    vector<vector<char>* >* p_src_data = new vector<vector<char>* >;
    int paste_t;
    argv[1] ? paste_t = atoi(argv[1]) : paste_t = 3;
    int black_sum = pasting(p_src_data, paste_t);
    cout << black_sum << endl;
    return 0;
}

int pasting(vector<vector<char>* >* p_src_data, int paste_t)
{
    int black_sum = 0; 
    int tmp_sum, paste_b;
    tmp_sum = 0;
    int width, height;
    width = ((*p_src_data)[0])->size();
    height = p_src_data->size();
    paste_b = get_paste_b(p_src_data);

    for(int i = 0; i < width - 1; ++i)
    {
        for(int j = 0; j < height - 1; ++j)
        {
            if('b' == (*(*p_src_data)[i])[j])  
            {
                'b' == (*(*p_src_data)[i + 1])[j + 1] ? tmp_sum += 1 : tmp_sum;  
            }
        }
    }
    black_sum = (paste_t - 1) - tmp_sum * (paste_b - tmp_sum) + paste_b;
    return black_sum;
}

int get_paste_b(vector<vector<char>* >* p_src_data)
{
    int width, height;
    width = ((*p_src_data)[0])->size();
    height = p_src_data->size();
    int result = 0;
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            if('b' == (*(*p_src_data)[i])[j])  
            {
                result++;
            }
        }
    }
    return result;
}
