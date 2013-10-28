#include <iostream>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;
#define MAX_LIMIT = 10000

int main(int argc, const char* argv[]){
    int data = {{1,2,3},
                {2,3,4},
                {3,4,5}};
/*
    int k = 3, curr, tmp_min = MAX_LIMIT, i = 0, step = 1;
    stack<int> step_rec;  
    do{
        int j;
        for(j = 0; j < k; ++j){
            int tmp = abs(data[0][i]) - data[1][j]; 
            if(tmp_min >= tmp){
                tmp_min = tmp;
            }
        }
        curr = data[1][j];
        step_rec.push(data[0][i]);
        step_rec.push(data[1][j]);
    }while(i < k)
*/   
    int k = 3, i = 0, step = 1;
    vector<int> curr(k);
    vector<int> tmp_min(k, MAX_LIMIT); 
    for(int c = 0; c < k; ++c) tmp_min[c] = MAX_LIMIT;
    stack<vector<int> > step_rec;
    
    do{
        int j; 
        for(j = 0; j < k; ++j){
            int tmp = abs(data[0][i]) - data[1][j]; 
            if(tmp_min[k - 1] > tmp) tmp_min[k - 1] = tmp;
            curr.push_back(j);
            tmp_min.sort();
        }
        step_rec.push(tmp_min);
    }while(i < k)
    
    for(vector<int>::iterator itmp = tmp_min.begin(); itmp != tmp_min.end(); ++itmp){
        *itmp = MAX_LIMIT;
    }
    while(step < k){
        int tmp_curr; 
        int s;
        for(s = 0; s < k; ++s){
            for(i = 0; i < k; ++i){
                int tmp = abs(curr[s] - data[step + 1][i]);
                if(tmp_min > tmp) tmp_min = tmp;
                tmp_curr = i;
            }
            curr.push_back(tmp_curr);
        }
        step++;
        stack_rec.push(data[step][curr[s]]);
    }
/*
    tmp_min = MAX_LIMIT;
    while(step < k){
        int tmp_curr = curr;
        for(i = 0; i < k; ++i){
            int tmp = abs(curr - data[step + 1][i]);
            if(tmp_min > tmp) tmp_min = tmp; 
            tmp_curr = i; 
        }
        curr = tmp_curr;
        step++;
        step_rec.push(data[step][curr]);
    }
*/
    return 0;
}
