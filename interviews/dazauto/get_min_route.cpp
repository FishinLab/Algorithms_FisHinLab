#include <iostream>

using namespace std;

#define MAX_LIMIT 10000
int get_distance(int one, int two){
    return one > two ? one - two : two - one;
}

int main(int argc, const char* argv[]){
    int mat[4][5] = {{5, 8, 15, 25, 36},
                   {0, 4, 18, 50}, 
                   {3, 7, 20, 30, 45},
                   {1, 2, 4}};
    int len_arr[4] = {5, 4, 5, 3};
    int min_dist = MAX_LIMIT, now_step = 0, start_step;
    for(int i = 0; i < len_arr[0]; ++i){
        for(int j = 0; j < len_arr[1];++j){
            int tmp_dist = get_distance(mat[0][i], mat[1][j]);
            if(min_dist >= tmp_dist){
                min_dist = tmp_dist;
                now_step = j;
                start_step = i;
            }
        }
    } 
    cout << mat[0][start_step] << " -> " << mat[1][now_step] << " -> ";  
    int c = 2, k = 4, next_step;
    while(c < k){
        min_dist = MAX_LIMIT;
        for(int i = 0; i < len_arr[c]; ++i){
            int tmp_dist = get_distance(mat[c - 1][now_step], mat[c][i]);
            if(min_dist >= tmp_dist){
                min_dist = tmp_dist;
                next_step = i;
            } 
        }
        cout << mat[c][next_step] << " -> ";
        c++;
    }
    cout << "done " << endl; 
    return 0;
}
