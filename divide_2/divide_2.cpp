#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

#ifndef SMALL
#define SMALL 0.001
#endif

int main(int argc, const char* argv[])
{
    const char* num = argv[1];
    int index = atoi(argv[2]);
    string check_num;
    int length = strlen(num);

    for(int i = index; i > 0; --i)
    {
        check_num += num[length - i]; 
    }

    int div_num = atoi(check_num.c_str());
    if(SMALL <= (div_num / int(pow(2, index))))
    {
        printf("%d could be deivied by %f\n", atoi(num), pow(2, index));
    }
    else    printf("%d could not be deivied by %f\n", atoi(num), pow(2, index));
    return 0;
}
