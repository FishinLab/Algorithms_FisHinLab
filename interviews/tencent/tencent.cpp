#include <iostream>

using namespace std;

void tencent(int* input_data, int* res_data, int length)
{
    for(int i = 0; i < length; ++i) res_data[i] = input_data[i]; 
    for(int i = 0; i < length; ++i)
    {
    
    }
}

int main(int argc, const char** argv)
{
    int* input_data = new int[argc - 1];
    int* res_data = new int[argc - 1]; 
    int length = argc - 1;
    for(int i = 1; i < argc; ++i) 
    {
        input_data[i] = atoi(argv[i]);
        res_data[i] = 1;
    }

    tencent(input_data, res_data, length);

    for(int i = 0; i < length; ++i) fprintf(stdout, " %d", res_data[i]);
    fprintf(stdout, "\n");
    return 0;
}
