#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[])
{
    int para = atoi(argv[1]);
    int fab_1 = 1;
    int fab_2 = 1;
    int fab_now = 0; 
    if(1 == para)
    {
        cout << fab_1 << endl;
    }
    else if(2 == para)
    {
        cout << fab_2 << endl;
    }
    else
    {
        int c = 3;
        int fab_now = fab_1 + fab_2;
        while(c <= para)
        {
            fab_now = fab_1 + fab_2;
            fab_1 = fab_2;
            fab_2 = fab_now;
            c++;
        }
        cout << fab_now << endl;
    }
    return 0;
}
