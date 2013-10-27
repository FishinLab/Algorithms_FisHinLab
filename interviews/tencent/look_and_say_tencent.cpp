#include <iostream>

using namespace std;

bool hashed(int* hash_values)
{
    int* tmp_values = hash_values; 
    for(int i = 0; i < 10; ++i)
    {
        for(int j = i; j < 10; ++j)
        {
            if(tmp_values[i] == tmp_values[j]) tmp_values[i]++;
        }
        if(tmp_values[i] != hash_values[i]) return false;
    }
    return true;
}

void look_and_say_tencent(int* data, int length)
{
    pair<int, int>* hash_keys = new pair<int, int>;
    int* hash_values = new int[10];
    for(int i = 0; i < 10; ++i)
    {
        pair<int, int> tmp_pair(i, 0);
        hash_keys[i] = tmp_pair;
        hash_values[i] = 0;
    }
    while(true)
    {
        if(!hashed(hash_values))
            hash_values = hashed(hash_values);
        else break;
    }
}

int main(int argc, const char** argv)
{
    int* data = new int[argc - 1];
    for(int i = 1; i < argc; ++i) data[i - 1] = atoi(argv[i]);
    int length = argc - 1;
    look_and_say_tencent(data, length);
    for(int i = 0;i < length; ++i) fprintf(stdout, " %d", data[i]);
    fprintf(stdout, "\n");
    return 0;
}
