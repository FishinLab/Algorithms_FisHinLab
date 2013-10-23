#include <iostream>
#include <string>

using namespace std;

string strstr(string, string);

int main(int argc, const char* argv[])
{
    string src_data(argv[1]);
    string cmp_data(argv[2]);
    string res_data = strstr(src_data, cmp_data);
    cout << res_data << endl;
    return 0;
}

string strstr(string src_data, string cmp_data)
{
    int i = 0, length = cmp_data.size();
    while(true)
    {
        if(src_data[i]++ == cmp_data[i]++ && i < length)
        { cout << src_data }
    }
}
