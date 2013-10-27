#include <iostream>

using namespace std;

void translate_numbers(int* data, int length){
    if(NULL == data) return;
    int i = 0;
    //one letter case:
    while(i < length){
        cout << (char)(data[i] + (int)('a') - 1) << " ";
        i++;
    }
    cout << endl;
    i = 0;
    //two letter case:
    while(i < length - 1){
        if(data[i] * 10 + data[i + 1] <= 26){
            cout << (char)((data[i] * 10 + data[i + 1]) + (int)('a') - 1) << " ";
        } 
        i++; 
    }
    cout << endl;
}

int main(int argc, const char* argv[]){
    int* data = new int[argc - 1];
    for(int i = 1; i < argc; ++i) data[i - 1] = atoi(argv[i]);
    int length = argc - 1;
    translate_numbers(data, length);
    return 0;
}
