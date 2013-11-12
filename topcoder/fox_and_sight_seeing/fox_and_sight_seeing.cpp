#include <iostream>
#include <math.h>

using namespace std;
#define MAX_LIMIT 100000

int get_dist(int* data, int len){
    int res;
    for(int i = 0; i < len - 1; ++i){
        res += abs(data[i] - data[i + 1]);
    }
    return res;
}

int main(int argc, const char* argv[]){
    int length = argc - 1;
    int* data = new int[length];
    for(int i = 0; i < length; ++i) data[i] = atoi(argv[i + 1]);
    int result = MAX_LIMIT; 
    int c = 0;
    while(c < length){
        int* tmp_data = new int[length - 1]; 
        for(int j = 0; j < length; ++j){
            if(j == c) continue;
            tmp_data[j] = data[c];
            c++;
        } 
        int dist = get_dist(tmp_data, length - 1);
        if(result > dist) result = dist;
    }

    cout << "fox_and_sight_seeing: " << result << endl;
    return 0;
}
