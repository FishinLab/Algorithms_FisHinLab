#include <iostream>
#include <vector>

using namespace std;

vector<int> check_color(vector<char>*, vector<char>*);
int get_number(vector<int>, int);

int main(int argc, const char* argv[])
{
    vector<char>* color_a = new vector<char>;
    vector<char>* color_b = new vector<char>;
    vector<int> colors = check_color(color_a, color_b);
    int num = atoi(argv[1]); 
    int result = get_number(colors, num);
    cout << result << endl;
    return 0;
}

vector<int> check_color(vector<char>* color_a, vector<char>* color_b)
{
    int length = color_a->size();
    vector<int> colors(length, 0);
    for(int i = 1;i < length; ++i)
    {
        ((*color_a)[i] == (*color_a)[i - 1]) || ((*color_b)[i] == (*color_b)[i - 1]) ? colors[i] = dynamic_cast<int>((*color_a))[i] : colors[i];
    }
    return colors;
}

int get_number(vector<int> colors, int num)
{
    int result = 0;
        
    return result;
}
