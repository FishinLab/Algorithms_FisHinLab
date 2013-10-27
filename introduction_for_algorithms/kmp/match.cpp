#include <iostream>
#include <string>
#include "kmp.h"

using namespace std;

int kmp_match(const string& data, const string& pattern){
    int* overlay_data = compute_overlay(pattern);  
    int pattern_index = 0, target_index = 0;
    while(pattern_index < pattern.size() && target_index < data.size()){
        if(data[target_index] == pattern[pattern_index]){
            target_index++;
            pattern_index++;
        }
        else if(pattern_index == 0){
            target_index++;
        }
        else{
            pattern_index = overlay_data[pattern_index - 1] + 1;
        }
        if(pattern_index == pattern_index){
            return target_index - pattern_index;
        }
        else return -1;
    }
} 

int main(int argc, const char* argv[]){
    string data(argv[1]);
    string pattern(argv[2]);
    cout << kmp_match(data, pattern) << endl;
    return 0;
}
