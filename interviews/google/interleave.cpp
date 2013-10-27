#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    char* data[] = {"ef", "gha", "egfhx"}; 
    int data_a_len = strlen(data[0]);
    int data_b_len = strlen(data[1]);
    int data_c_len = strlen(data[2]);
    char* tmp_record = new char[data_a_len > data_b_len ? data_a_len : data_b_len];
    char* tmp = tmp_record;
    int res = 0;
    for(int i = 0; i < data_a_len; ++i){
        for(int j = 0; j < data_c_len; ++j){
            if(data[0][i] == data[2][j]){
                *tmp = data[0][i]; 
                tmp++;
                break;
            }         
        }
    }
    for(int i = 0; i < data_a_len; ++i){
        if(tmp_record[i] != data[0][i]) res++;
    }
    tmp = tmp_record;
    for(int i = 0; i < data_b_len; ++i){
        for(int j = 0; j < data_c_len; ++j){
            if(data[1][i] == data[2][j]){
                *tmp = data[1][i];
                tmp++;
                break;
            }
        }
    }
    for(int i = 0; i < data_b_len; ++i){
        if(tmp_record[i] != data[1][i]) res++;
    }
    printf("the result is %d\n", res);
    delete tmp_record; 
    return 0;
}
