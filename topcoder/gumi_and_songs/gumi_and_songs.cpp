#include <iostream>

using namespace std;
#ifndef MAX_LIMIT
#define MAX_LIMIT 2048
#endif

void patition(int* data_arr, int length, int index)
{
    for(int i = 0; i < length; ++i)
    {
        if(data_arr[i] >= data_arr[index]) 
        {
            int tmp = data_arr[i];
            data_arr[i] = data_arr[index];
            data_arr[index] = tmp;
            index = i;
        }
    }
}

void quick_sort(int* data_arr, int left, int right)
{
    if(right >= left) return;
    else
    {
        int pivot = int((left + right) / 2);
        int length = right - left + 1;
        patition(data_arr, length, pivot); 
        quick_sort(data_arr, left, pivot - 1);
        quick_sort(data_arr + pivot, pivot, right);
    }
}

int main()
{
    int* duration = new int[MAX_LIMIT]; 
    int* tones = new int[MAX_LIMIT];
    int t = 0;
    
    scanf("duration time :", duration);
    scanf("tones time :", tones);
    scanf("total time:", t);
    
    int length = sizeof(duration);
    quick_sort(duration, 0, length);
    quick_sort(tones, 0, length);

    int c = 0, res = 0, ret;
    while(c < length)
    {
        if(res += duration[c] <= t) c++; 
        if(c != length) res += (tones[c + 1] - tones[c]);
    }
    fprintf(stdout, "gumi could sing : %d songs\n", c);
    return 0;
}
