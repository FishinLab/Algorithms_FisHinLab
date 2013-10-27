#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[]){
    string data(argv[1]);
    int length = strlen(argv[1]);
    char p_str = data[1], tmp_p = data[0];
    int i = 1; 
    while(i < length){
        if(data[i] == '*')
            data[i] = data[i - 1];
        i++;
    }
    cout << data << endl;
    return 0;
}
