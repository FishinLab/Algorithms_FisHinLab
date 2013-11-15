/*
 * The game DAG:
 * The game is divided into N missions numbered from 1 to N, The order of competing the mission is not linear, there might be several missions which can be attempted at the same game.
 * Some missions' completion is a prerequistie for attempting other missions.
 * More specifically, a direct acyclic graph which N vertice is associated with the game.
 * Each arc(i, j) in this DAG means that the mission i is prerequistie of mission j and thus mission j cannot be attempted before mission i is completed.
 * Note that this DAG may or may not contain redundant arcs;
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[]){
    int length = argc - 1;
    int* step = new int[length];
    for(int i = 0; i < length - 2; ++i) step[i] = atoi(argv[i + 1]);
    int from = atoi(argv[length - 2]), to atoi(argv[length - 1]);
    return 0;
}
