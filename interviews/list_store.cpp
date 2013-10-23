#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct s_points{
    double x;
    double y;
}_s_points;

double get_distance(s_points client, s_points p){
    return sqrt(pow((client.x - p.x), 2) + pow((client.y - p.y), 2));  
}

int main(int argc, const char* argv[]){
    s_points* data = new s_points[5];
    s_points p_0;
    s_points p_1;
    s_points p_2;
    s_points p_3;
    s_points p_4;

    p_0.x = 1.0;
    p_0.x = 1.0;

    p_1.x = -2.0;
    p_1.x = 1.0;

    p_2.x = 2.0;
    p_2.x = -1.0;

    p_3.x = 3.0;
    p_3.x = 4.0;

    p_4.x = -5.0;
    p_4.x = -5.0;

    data[0] = p_0;
    data[1] = p_1;
    data[2] = p_2;
    data[3] = p_3;
    data[4] = p_4;

    s_points client;
    client.x = 0.0;
    client.y = 0.0;

    double radia = 2.0;
    for(int i = 0; i < 5; ++i){
        if(get_distance(client, data[i]) <= radia){
            printf("x: %f y: %f\n", data[i].x, data[i].y);
        }
    }
    return 0;
}
