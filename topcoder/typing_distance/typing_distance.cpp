#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int get_distance(string, char, char);

int main(int argc, const char* argv[])
{
    string keyboard(argv[1]);
    string type_str(argv[2]);
    int type_str_len = type_str.size();
    int result = 0;
    for(int i = 1; i < type_str_len; ++i)
    {
        result += get_distance(keyboard, type_str[i - 1], type_str[i]); 
    }
    cout << result << endl;
    return 0;
}

int get_distance(string keyboard, char c_from, char c_to)
{
    int distance = 0;
    int i_from = -1;
    int i_to = -1;
    int length = keyboard.size();
    int i = 0;
    while(0 > i_from * i_to)
    {
        c_from == keyboard[i] ? i_from = i : i_from;
        c_to == keyboard[i] ? i_to = i : i_to;
        i = (i++) % length;
    }
    distance = abs(i_to - i_from) + 1;
    return distance;
}
