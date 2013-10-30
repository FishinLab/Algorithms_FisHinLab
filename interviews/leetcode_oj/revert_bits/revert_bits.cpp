#include <iostream>

using namespace std;

void revert_bits(char* data, int len){
    char* p = &(data[0]);
    char* q = data + len - 1;

    while(len > 0){
        char tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
        len = len - 2;
    }
    cout << "revert_bits: " << data << endl;
}

void bi_revert_bits(char* data, int len){
    if(1 == len) return; 
    /*
    char* new_data = new char[len]; 
    strncpy(new_data, (const char*)data, (int)(len / 2));
    data = data + (int)(len / 2);
    int c = 0;
    while(c < (int)(len / 2)){
        new_data[c + (int)(len / 2)] = data[c];
        c++;
    }
    */
    revert_bits(data, len);
    cout << data << endl;
    bi_revert_bits(data, (int)(len / 2));
    bi_revert_bits(data + (int)(len / 2), (int)(len / 2));
}

int main(int argc, const char* argv[]){
    char* data = const_cast<char*>(argv[1]);
    int len = strlen(data);

    revert_bits(data, len);
    bi_revert_bits(data, len);
    return 0;
}
