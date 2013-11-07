#include <iostream>

using namespace std;

bool is_outof_range(string code){
    if(0 < atoi(code.c_str()) && 26 >= atoi(code.c_str())) return false;
    return true;
}

void decode_ways(string code, int &result){
    if(1 == code.size()){
        result++;
        return;    
    }else if(2 == code.size()){
        is_outof_range(code) ? result++ : result += 2;
        return;
    }else if(is_outof_range(code.substr(0, 2))){
        result++;
        decode_ways(code.substr(1, code.size() - 1), result);
    }else{
        result = result + 2;
        decode_ways(code.substr(2, code.size() - 2), result);
    }
}

int main(int argc, const char* argv[]){
    string code(argv[1]);
    int result = 0;
    decode_ways(code, result);
    printf("decode_ways: %d\n", result);
    return 0;
}
