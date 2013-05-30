#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int get_key_press(string, string);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    int result = 0;
    vector<string*>* p_src_data = new vector<string*>;
    for(int i = 1; i < argc; ++i)
    {
        string tmp_str(argv[i]);
        //string* p_tmp_str = &tmp_str;
        p_src_data->push_back(&tmp_str);
    }
    int i = 0;
    do
    {
        i++; 
        string curr_keys = *((*p_src_data)[i]);
        string history = *((*p_src_data)[i - 1]); 
        //result += get_key_press(*((*p_src_data)[i]), *((*p_src_data)[i - 1]));
        result += get_key_press(curr_keys, history);
    }while(i < data_scale);
    cout << result << endl;
    return 0;
}

int get_key_press(string curr_keys, string history)
{
    int num_pressed = 0;
    int length = min(curr_keys.size(), history.size());
    for(int i = 0; i < length; ++i)
    {
        if(curr_keys[i] == history[i])
        {
            continue;
        }
        else
        {
            num_pressed += 2;
            break;
        }
    }
    num_pressed += curr_keys.size();
    return num_pressed;
}
