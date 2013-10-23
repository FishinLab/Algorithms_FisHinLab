/*
 *  Given two sorted arrays A, B of size m and n. Find the k-th smallest element in the union of A and B.
 *  Assume that there are no duplicated elements
 * */
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    int data_a[5] = {4, 5, 6, 7, 8};
    int data_b[6] = {5, 6, 7, 8, 9, 10};
    int k = 1;
    int i = k, j = k;
    while(data_a[i] != data_b[j]){
        if(data_a[i] > data_b[j]) j++;
        else if(data_a[i] < data_b[j]) i++;
    }
    cout << data_a[i] << " " << data_b[j] << endl;
    return 0;
}

