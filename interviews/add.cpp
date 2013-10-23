#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[])
{
    int ele_arr[] = {1,2,4,7,11,15};
    int i_sum = atoi(argv[1]);
    
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(i_sum == ele_arr[i] + ele_arr[j])
            {
                cout << ele_arr[i] << " " << ele_arr[j] << endl;
            }
        }
    }
    return 0;
}
