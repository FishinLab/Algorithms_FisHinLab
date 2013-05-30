#include <iostream>
#include <vector>

using namespace std;

int get_length(string nickname)
{
    int result = 0;
    char temp[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int len = nickname.size(); 

    vector<int> tmp(1);
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            if(temp[j] == nickname[i])
            {
                tmp[0]++;
            }
            else{
                tmp.push_back(1);
            }
        }
    }
    result = tmp.size();
    return result;
}

int main(int argc, const char* argv[])
{
    string para(argv[1]);
    int result = get_length(para);
    cout << result << endl;
    return 0;
}
