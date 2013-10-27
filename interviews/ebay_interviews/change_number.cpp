#include <iostream>
#include <map>

using namespace std;

void init_data_map(map<int, const char*> data_map){
    pair<int, const char*> tmp;
    int c = 1;
    while(c <= 9){
        tmp.first = c;
        data_map[tmp.first] = "";
        c++;
    }
    data_map[1] = "one";
    data_map[2] = "two";
    data_map[3] = "three";
    data_map[4] = "four";
    data_map[5] = "five";
    data_map[6] = "six";
    data_map[7] = "seven";
    data_map[8] = "eight";
    data_map[9] = "nine";
}

void init_sep_data(map<int, const char*> special_data_map){
    pair<int, const char*> tmp;
    int c = 1;
    while(c <= 9){
        tmp.first = c;
        special_data_map[tmp.first] = "";
        c++;
    }
    special_data_map[2] = "twenty";
    special_data_map[3] = "thirty";
    special_data_map[4] = "fourty";
    special_data_map[5] = "fifty";
    special_data_map[6] = "sixty";
    special_data_map[7] = "seventy";
    special_data_map[8] = "eighty";
    special_data_map[9] = "ninety";

}

int main(int argc, const char* argv[]){
    map<int, const char*> data_map;
    map<int, const char*> special_data_map;
    init_data_map(data_map);
    init_sep_data(special_data_map);
    const char* num_data = argv[1];
    int c = 0, length = strlen(num_data);
    printf("%s thousand and %s hundrurd %s %s\n", 
            data_map[length], data_map[length - 1], special_data_map[c + 1], special_data_map[c]);
    return 0;
}
