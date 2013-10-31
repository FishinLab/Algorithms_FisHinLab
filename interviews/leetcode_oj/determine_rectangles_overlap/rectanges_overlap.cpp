#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    pair<int, int> p_one, p_two, p_three, p_four;
    p_one.first = atoi(argv[1]);
    p_one.second = atoi(argv[2]);

    p_two.first = atoi(argv[3]);
    p_two.second = atoi(argv[4]);

    p_three.first = atoi(argv[5]);
    p_three.second = atoi(argv[6]);

    p_four.first = atoi(argv[7]);
    p_four.second = atoi(argv[8]);

    if(p_one.first <= p_three.first && p_one.second <= p_three.second && p_two.first >= p_three.first && p_two.second >= p_three.second){
        printf("overlap\n");
    }else if(p_one.first <= p_three.first && p_one.second >= p_three.second && p_two.first >= p_three.first && p_two.second >= p_three.second){
        printf("overlap\n");
    }else printf("not overlap\n");

    return 0;
}
