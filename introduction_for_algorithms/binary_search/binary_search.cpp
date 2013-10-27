#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>* src_data, int low, int high, int key)
{
    int mid = (low + high) / 2;
    if(low > high) return mid;
    else if((*src_data)[mid] > key)
    {
        return binary_search(src_data, low, mid - 1, key);
    }
    else return binary_search(src_data, mid + 1, high, key);
}

int main(int argc, const char** argv)
{
    vector<int>* src_data = new vector<int>;
    for(int i = 1; i < argc; ++i) src_data->push_back(atoi(argv[i]));
    int low = 0, high = src_data->size();
    int key;
    scanf("%d", &key);
    printf("key : %d \n", key);

    int res = binary_search(src_data, low, high, key);
    printf("result is %d\n", res);
    return 0;
}

