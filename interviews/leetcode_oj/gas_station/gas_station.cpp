#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, const char* argv[]){
    int data_scale = atoi(argv[1]);
    int* gas = new int[data_scale];
    int* cost = new int[data_scale];

    //for(int i = 0; i < data_scale; ++i) cout << "gas station " << i << " keeps gas: " << gas[i];
    //cout << endl;
    //for(int i = 0; i < data_scale; ++i) cout << "gas costs: " << cost[i];
    //cout << endl;
    
    //gas[0] = 3; gas[1] = 4; gas[2] = 5;
    //cost[0] = 1; cost[1] = 2; cost[2] = 3;

    //gas[0] = 1; gas[1] = 0; gas[2] = 1;
    //cost[0] = 1; cost[1] = 2; cost[2] = 3;

    gas[0] = 1; gas[1] = 2; gas[2] = 3;
    cost[0] = 1; cost[1] = 2; cost[2] = 3;

    int tank = 0, start = 0;
    do{
        bool flag = true;
        start++; 
        for(int i = 0; i < data_scale; ++i){
            if((tank - cost[i] + gas[i] ) < 0){
                flag = false;
                break;
            } 
        }
        if(!flag){
            cout << "could not make a round travel" << endl;
        }else cout << "from " << start << " gas station, it's good" << endl;
    }while(start % data_scale != start);

    return 0;
}
