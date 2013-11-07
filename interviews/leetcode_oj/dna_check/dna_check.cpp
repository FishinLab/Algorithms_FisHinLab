/*
 *Given a DNA sequence and sub sequence which bad, compute the mininum number for changing DNA sequence to perfect one.
 * e.g. DNA:        AAAG
 *      bad DNA:    AAA AAG
 *      result:     1
 * */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void dna_check(string data, vector<string> &dict){
    if(0 == data.size() || 0 == dict.size()) return; 
    int data_len = data.size();
    int c = 0, dict_len = dict.size();
    int result = 0;
    vector<pair<int, int> > range;
    while(c < dict_len){
        for(int i = 0; i < data_len; ++i){
            if(dict[c] == data.substr(i, dict[c].size())){
                pair<int, int> tmp(i, dict[c].size());
                range.push_back(tmp);
                break;
            }
        }
        c++;
    }
    for(int i = 0; i < range.size() - 1; ++i){
        if(range[i].first + range[i].second >= range[i + 1].first) result++;
    }
    printf("dna_check: %d\n", result);
}

int main(int argc, const char* argv[]){
    int length = argc - 1;
    string data(argv[1]);
    vector<string> dict;
    int c = 2;
    while(c < length + 1){
        string tmp(argv[c]);
        dict.push_back(tmp);
        c++;
    }
    dna_check(data, dict);
    return 0;
}
