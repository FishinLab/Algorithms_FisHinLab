#include <iostream>
#include <vector>

using namespace std;

struct hist{
    double start;
    double end;
}_hist;

int main(int argc, const char* argv[]){
    double data[5] = {1.2, 3.1, 0.5, 10.9, 2};
    double boundry[3] = {0, 1.5, 4};
    int len_data = 5, len_bound = 3;
    hist record, result; 
    vector<hist> record;
    for(int i = 0; i < len_bound - 1; ++i){
        hist tmp_hist;
        tmp_hist.tart = boundry[i];
        tmp_hist.end = boundry[i + 1];
        record.push_back(tmp_hist);
    }
    int c = 0;
    while(c < len_data){
        for(int i = 0; i < 2; ++i){
            if(data[c] <= record[i].second && data[c] >= record[i]);
            result.
        }
        c++;
    }
    return 0;
}
