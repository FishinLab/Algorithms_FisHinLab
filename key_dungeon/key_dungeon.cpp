#include <iostream>
#include <math.h>

using namespace std;

int max_keys(int* door_R, int* door_G, int* room_R, int* room_G, int* room_W, int* keys, int length)
{
    int remain_keys = 0;
    for(int i = 0; i < length; ++i)
    {
        int tmp_sum = 0;
        for(int j = 0; j < length; ++j) tmp_sum += keys[i];
        if(door_R[i] <= keys[0] + keys[2] && door_G[i] <= keys[1] + keys[2] && door_R[i] + door_G[i] < tmp_sum) 
        {
            int benifit = room_R[i] + room_G[i] + room_W[i]; 
            int cost = door_R[i] + door_G[i];
            if(benifit > cost) // open the door
            {
                if(keys[0] - door_R[i] > 0) keys[0] -= door_R[i];
                else 
                {
                    keys[0] = 0;
                    keys[2] -= abs(keys[0] - door_R[i]);
                }

                if(keys[0] - door_G[i] > 0) keys[1] -= door_G[i];
                else
                {
                     keys[1] = 0;
                     keys[2] -= abs(keys[0] - door_G[i]);
                }
                keys[0] += room_R[i];
                keys[1] += room_G[i];
                keys[2] += room_W[i];
            }
            else continue;
        }
    }
    for(int j = 0; j < length; ++j) remain_keys += keys[j]; 
    return remain_keys;
}

int main(int argc, const char** argv)
{
    int door_R[4] = {1, 2, 3, 1};
    int door_G[4] = {0, 4, 9, 2};
    int room_R[4] = {0 ,0 ,10, 3};
    int room_G[4] = {0, 8, 9, 4};
    int room_W[4] = {1, 0, 8, 5};
    int keys[3] = {3, 1, 2};

    int length = sizeof(keys) / sizeof(int);

    int res = max_keys(door_R, door_G, room_R, room_G, room_W, keys, length);
    fprintf(stdout, "remain max number of keys is : %d\n", res);
    return 0;
}
