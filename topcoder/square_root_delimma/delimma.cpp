#include <iostream>
#include <math.h>

using namespace std;

int delimma(pair<int, int>);

int main(int argc, const char* argv[])
{
    pair<int, int> src_data;
    src_data.first = atoi(argv[1]); 
    src_data.second = atoi(argv[2]); 
    int result = delimma(src_data);
    cout << result << endl;
    return 0; 
}

int delimma(pair<int, int> src_data)
{
    int sum = 0;
    for(int i = 1; i <= src_data.first; ++i)
    {
        for(int j = 1; j <= src_data.second; ++j)
        {
            double ssr = pow((sqrt((double)i) + sqrt((double)j)), 2); 
            if(ceil(ssr) == floor(ssr))
            {
                sum += 1; 
            }
        }
    }
    return sum;
}
