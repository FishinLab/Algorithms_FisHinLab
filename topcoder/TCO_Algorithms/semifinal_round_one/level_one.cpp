/* Rabbits and cakes: 
 * Let the number of rabbits be R and the number of cakes C.
 * All C cakes are the same size. Each cake may be cut into two pieces(of possibly non-equal sizes) or kept uncut
 * Then the cakes and pieces of cake are distributed among the rabbits, so that all of rabbits get the same amount of cake(C/R) 
 *
 * given R is between minR aand MaxR inclusive, C between minC and MaxC return the number of pairs (R, C) for which the division of cakes described above is possble
 * */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int is_match(int tmp_c, vector<pair<int, int> > &cut){
    int length = cut.size();
    for(int i = 0; i < length; ++i){
        if(tmp_c == cut[i].first || tmp_c == cut[i].second) return i;  
    }
}

void rabbits_and_cakes(int r,int c){
    if(r == c){
        printf("rabbits_and_cakes: r %d, c %d\n", r, c);
        return;
    }

    vector<pair<int, int> > cut; 
    for(int i = 1; i <= ceil(r/2); ++i){
        pair<int, int> tmp(i, r - i);
        cut.push_back(tmp);
    }
    
    int k = 0;
    while(k < c){
        int tmp_c = c - cut[0].first;
        int index = is_match(tmp_c, cut);
        if(index != 0){
            if(tmp_c == cut[index].first){
                pair<int, int> tmp(0, cut[index].second);
                cut[index] = tmp;
            }else if(tmp_c == cut[index].second){
                pair<int, int> tmp(cut[index].first, 0);
                cut[index] = tmp;
            }
        }else break; 
        c++;
    }
    
    for(int i = 0; i < cut.size(); ++i){
        pair<int, int> check_p(0, 0);
        if(cut[i] == check_p) printf("rabbits_and_cakes: r %d, c %d\n", r, c);
    }
    return;
}

int main(int argc, const char* argv[]){
    int min_r = atoi(argv[1]);
    int max_r = atoi(argv[2]);
    int min_c = atoi(argv[3]);
    int max_c = atoi(argv[4]);

    for(int i = min_r; i <= max_r; ++i){
        for(int j = min_c; j <= max_c; ++j){
        rabbits_and_cakes(i, j);            
        }
    }
    return 0;
}
