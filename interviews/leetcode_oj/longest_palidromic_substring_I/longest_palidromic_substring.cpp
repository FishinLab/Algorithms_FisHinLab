#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
#define MAX_LIMIT 100000

bool is_palidromic(string data, int start, int end){
    while(start <= end){
        if(data[start] != data[end]) return false;
        start++;
        end--;
    }
    return true;
}

void longest_palidromic_substring(string data, vector<pair<int, int> > &rec){
    int i, j;
    i = 0; j = 0; 
    pair<int, int> tmp; 
    while(i < data.size()){
        if(is_palidromic(data, i, j)){
            tmp.first = i;
            tmp.second = j;
            rec.push_back(tmp);
            j++;
        }else{
            i++; 
            j = i;
        }
    }
}

int main(int argc, const char* argv[]){
    string data(argv[1]);
    vector<pair<int, int> > rec;

    longest_palidromic_substring(data, rec);

    int res = 0; 
    for(vector<pair<int, int> >::iterator ir = rec.begin(); ir != rec.end(); ++ir){
        if(res <= abs((*ir).first - (*ir).second)) res = abs((*ir).first - (*ir).second) + 1; 
    }
    cout << "longest_palidromic_substring: " << res << endl;
    return 0;
}
