#include <iostream>
#include <vector>

using namespace std;

int fab(int para)
{
    if(3 > para)
    {
        return 1;
    }
    else
    {
        return fab(para - 1) + fab(para - 2);
    }
}

int main(int argc, const char* argv[])
{
    int para = atoi(argv[1]);
    cout << fab(para) << endl;
    return 0;
}
