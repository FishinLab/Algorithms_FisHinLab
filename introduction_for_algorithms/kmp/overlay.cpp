#include <iostream>
#include <string>
#include "kmp.h"

using namespace std;

int* compute_overlay(const string& pattern){
    const int length = pattern.size();
    int index;
    int *overlay_data = new int[length];
    overlay_data[0] = -1;
    for(int i = 1; i < length; ++i){
        index = overlay_data[i - 1];
        while(index >= 0 && pattern[i] != pattern[index + 1]){
            index = overlay_data[index];
        }
        if(pattern[i] == pattern[index + 1]){
            overlay_data[i] = index + 1;
        }else overlay_data[i] = -1;
    }
    return overlay_data;
}

int main(int argc, const char* argv[]){
    const string pattern(argv[1]);
    compute_overlay(pattern);
    return 0;
}
