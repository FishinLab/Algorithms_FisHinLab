#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef MAX
#define MAX 1000
#endif

int main(int argc, const char* argv[])
{
    char* src_data[][] = new char[MAX][MAX];
    int len = sizeof(argv[1]);
    for(int i = 0;i < len; ++i)
    {
        if(' ' == argv[1][i])
        {
        }
    }
    return 0;   
}
