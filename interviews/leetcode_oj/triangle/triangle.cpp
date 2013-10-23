#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void form_triangle(int* input_data , int length, int* res_data, vector<int*> triangles)
{
    vector<int*>iterator tr = triangles.begin();
    for(int i = 0; i < length; ++i){
        for(int j = i; j < length; ++j){
            for(int k = j; k < length; ++k){
                int tmp_sum = 0;
                input_data[i] + input_data[j] > input_data[k] ? tmp_sum++ : tmp_sum;
                input_data[j] + input_data[k] > input_data[i] ? tmp_sum++ : tmp_sum; 
                input_data[k] + input_data[i] > input_data[j] ? tmp_sum++ : tmp_sum;
                if(tmp_sum == 3){
                    (*tr)[0] = input_data[i];
                    (*tr)[1] = input_data[j];
                    (*tr)[2] = input_data[k];
                    tr++;
                }
         
        }
    }
}

int main(int argc, const char** argv)
{
    int* input_data = new int[argc - 1];
    for(int i = 1; i < argc;++i) input_data[i - 1] = atoi(argv[i]);
    int length = argc - 1;
    int* res_data = new int[argc - 1];
    int* init = new int[3]; 
    vector<int*> triangles(argc, init);
    form_triangle(input_data, length, res_data, triangles);
    for(vector<int*>::iterator i = triangles.begin(); i != triangles.end(); ++i)
    {
        printf(" %d %d %d\n", (*i)[0], (*i)[1], (*i)[2] );
    }
    delete[] input_data, res_data, init;
    return 0;
}
            }
