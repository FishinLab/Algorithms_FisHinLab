#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[]){
    int length = argc - 1;
    int* data = new int[length];
    for(int i = 0; i < length; ++i) data[i] = atoi(argv[i + 1]);
    vector<pair<int, int> > record;
    for(int i = 0; i < length; ++i){
        for(int j = i; j < length; ++j){
            if(data[i] + data[j] == 0){
                pair<int, int> tmp_p;
                tmp_p.first = data[i];
                tmp_p.second = data[j];
                record.push_back(tmp_p);
            } 
        } 
    }
    for(vector<pair<int, int> >::iterator ir = record.begin(); ir != record.end(); ++ir){
        for(vector<pair<int, int> >::iterator is = ir + 1; is != record.end(); ++is){
            printf("[%d %d %d %d]\n", (*ir).first, (*ir).second, (*is).first, (*is).second);
        }
    }
    return 0;
}
