#include <iostream>
#include <map>

using namespace std;

int get_one_two_three(int* input_data, int length){
    int res;
    map<int, int>* gott_map = new map<int, int>;
    for(int i = 0; i < length; ++i){
        if(NULL == (*gott_map)[input_data[i]]){
            (*gott_map)[input_data[i]] = 1;
        } 
        else (*gott_map)[input_data[i]]++;
    }
    length = gott_map->size();
    for(int i = 0; i < length; ++i){
        printf("%d ", (*gott_map)[input_data[i]]);
        if((*gott_map)[input_data[i]] == 3) return res;
    }
    return 0;
}

int main(int argc, const char* argv[])
{
    int* input_data = new int[argc - 1];
    int length = argc - 1;
    for(int i = 1; i < length; ++i) input_data[i - 1] = atoi(argv[i]);
    int result  = get_one_two_three(input_data, length);
    printf("the repeated trible time number is : %d\n" ,result);
    delete[] input_data;
    return 0; 
}
