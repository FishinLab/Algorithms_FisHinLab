#include <iostream>

using namespace std;

int get_duplicate(int* input_data, int length)
{
    for(int i = 0; i < length; ++i)
    {
        while(i < length)
        {
            if(input_data[input_data[i]] == i)
            {i++;}
            else return input_data[i];
        }
    }
}

int main(int argc, const char** argv)
{
    int* input_data = new int[argc - 1];
    for(int i = 1; i < argc; ++i) input_data[i - 1] = atoi(argv[i]); 
    int length = argc - 1;
    int res = get_duplicate(input_data, length);
    fprintf(stdout, "the duplicated one is : %d\n", res);
    return 0;
}
