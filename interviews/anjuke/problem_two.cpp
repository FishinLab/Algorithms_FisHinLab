#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(pair<int, int> exit, int** mat, stack<pair<int, int> > &record){
    if(exit.first - 1 && exit.first + 1 && exit.second - 1 && exit.second - 1){
        if(exit.first - 1 == 0){
            exit.first -= 1;
            record.push(exit);
            DFS(exit, mat, record);
        }else if(exit.first + 1 == 0){
            exit.first += 1;
            record.push(exit);
            DFS(exit, mat, record);
        }else if(exit.second - 1 == 0){
            exit.second -= 1;
            record.push(exit);
            DFS(exit, mat, record);
        }else{
            exit.second += 1;
            record.push(exit);
            DFS(exit, mat, record);
        }  
    }else return;
}

bool could_touch(pair<int, int> exit, pair<int, int> now, int** mat){
    stack<pair<int, int> > tmp_rec;
    DFS(now, mat, tmp_rec);
    while(tmp_rec.empty()){
        if(tmp_rec.top() == exit) return true;
        tmp_rec.pop();
    }
    return false;
}

int main(int argc, const char* argv[]){
    int mat[3][5] = {{0, 0, 0, 0, 0},
                     {1, 1, 1, 0, 1},
                     {2, 0, 0, 0, 2}}; 
    pair<int, int> exit_one(2, 0), exit_two(2, 4);
    stack<pair<int, int> > record;

    DFS(exit_one, (int**)mat, record);

    pair<int, int> cache;
    vector<pair<int, int> > steps;
    while(record.empty()){
        if(could_touch(exit_two, record.top(), (int**)mat)){
            cache = record.top();
            steps.push_back(record.top());
        }
        record.pop();
    }
    printf("the worst point is [%d %d]\n", cache.first, cache.second);
    printf("and the step number is %d\n", (int)steps.size());
    return 0;
}
