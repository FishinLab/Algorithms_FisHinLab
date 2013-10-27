#include <iostream>

using namespace std;

void get_last_one(int* input_data, int length)
{
    fprintf(stdout, "the last one is %d\n", input_data[length]); 
}

int main(int argc, const char** argv)
{
    int* input_data = new int[argc - 1];
    for(int i = 1; i < argc; ++i) input_data[i] = atoi(argv[i]);

    get_last_one(input_data, argc - 1);
    return 0; 
}
