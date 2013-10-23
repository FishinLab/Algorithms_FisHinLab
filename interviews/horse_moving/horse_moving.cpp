#include <iostream>

using namespace std;

void search_next_step(pair<int, int> pos_now, int board[4][5]){
    pair<int, int> next_step, start_pos;
    start_pos = pos_now;
    int sum = 0;
    for(next_step = pos_now; ;){
        //next_step.first = next_step.first + 1;
        //next_step.second = next_step.second + 2;
        next_step = next_step + pair<int, int>(1,2)
        if(board[next_step.first][next_step.second] == 0 && next_step.first < 4 && next_step.first >= 0 && next_step.second < 5 && next_step.second >= 0){
            if(next_step == start_pos) sum++;
            else{
                board[next_step.first][next_step.second] = 1;
                search_next_step(next_step, board);
                board[next_step.first][next_step.second] = 0;
            }
        }
    }

}

int main(){
    int board[4][5];
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 5; ++j){
            board[i][j] = 0;
        }
    }
    pair<int, int> pos_now;
    pos_now.first = 0;
    pos_now.second = 0;
    search_next_step(pos_now, board);
    return 0;
}
