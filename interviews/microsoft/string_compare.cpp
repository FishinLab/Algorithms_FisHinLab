#include <iostream>
#include <string>

using namespace std;

bool string_compare(string one, string two){
    if(sizeof(one) != sizeof(two)) return false;
    int i = 0;
    int length = sizeof(one);
    while(i < length){
        if(one[i] != two[i]) return false;
        i++;
    }
    return true;
}

int main(int argc, const char* argv[]){
    string one(argv[1]), two(argv[2]);
    string_compare(one, two) ? printf("match") : printf("nope");
    return 0;
}
