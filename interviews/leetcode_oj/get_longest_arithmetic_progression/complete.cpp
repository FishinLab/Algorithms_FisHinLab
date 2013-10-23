#include <iostream>

using namespace std;

void get_longest_arithmetic_progression(int* input_data, int length)
{
    int* start_index = input_data, *end_index = input_data + 1;
    int size = 1, tmp_minus = input_data[1] - input_data[0];
    for(int i = 0; i < length - 1; ++i)
    {
        if(input_data[i + 1] - input_data[i] == tmp_minus)
        {
            size++;
            end_index++;
        }
        else{
           start_index += (size - 1); 
           size = 1;
        }
    }

    while(start_index != end_index)
    {
        printf(" %d", *start_index);
        start_index++;
    }
    printf("\n");
}

int main(int argc, const char** argv)
{
    int* input_data = new int[argc - 1];
    for(int i = 1; i < argc; ++i) input_data[i - 1] = atoi(argv[i]);
    get_longest_arithmetic_progression(input_data, argc - 1);
    delete[] input_data;
    return 0;
}
