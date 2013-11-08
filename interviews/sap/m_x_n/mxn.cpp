/*
 * Given a mat[M][N], ouput every path from mat[0][0] to mat[M][N]
 * */

#include <iostream>
#include <vector>

using namespace std;
int data[4][5] = {{1, 2, 3, 4, 5},
                  {6, 7, 8, 9, 10},
                  {11, 12, 13, 14, 15},
                  {16, 17, 18, 19, 20}};

void do_go(pair<int, int> &curr, pair<int, int> &next, pair<int, int> &exit){
    if(curr == exit) return;
    printf("%d->", data[curr.first][curr.second]);
    //cout << "curr: " << curr.first << " " << curr.second << endl;
    int m = exit.first, n = exit.second;
    if(m == curr.first && n > curr.second){
        next.first = curr.first;
        next.second = curr.second + 1;
        do_go(next, next, exit);
    }else if(m > curr.first && n == curr.second){
        next.first = curr.first + 1;
        next.second = curr.second;
        do_go(next, next, exit);
    }else if(m > curr.first && n > curr.second){
        next.first = curr.first + 1;
        next.second = curr.second + 1;
        pair<int, int> tmp_next(curr.first + 1, curr.second);
        do_go(next, next, exit);
        do_go(tmp_next, next, exit);
        tmp_next.first = curr.first;
        tmp_next.second = curr.second + 1;
        do_go(tmp_next, next, exit);
    }else{
        printf("\n"); 
        return;
    }
}

int main(int argc, const char* argv[]){
    int m = 4, n = 5;
    pair<int, int> curr(0, 0), next(0, 0), exit(n, m);
    do_go(curr, next, exit);
    return 0;
}
