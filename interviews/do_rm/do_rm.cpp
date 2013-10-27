#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    const char* data[] = {"acbac", "aaac", "ababac", "bbbbd", "aaccac"};
    //char* cursor = const_cast<char*>(data[0]);
    char cursor[1024];
    int x = 0;
    while(x < sizeof(data) / sizeof(char*)){
        strcpy(cursor, data[x]);
        int c = strlen(cursor);
        int i;
        for(i = 0; i < c; ++i){
            if(cursor[i] == 'b'){
                cursor[i] = '@';
            }else if(cursor[i] == 'a' && cursor[i + 1] == 'c' && i != c){
                cursor[i] = '@';
                cursor[i + 1] = '@';
                i != 0 ? i = i - 2: i;
            }
        }
        for(int i = 0; i < strlen(cursor); ++i){
            if(cursor[i] != '@') cout << cursor[i];
        }
        cout << endl;
        x++;
    }
    return 0;
}
