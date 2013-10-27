#include <iostream>
#include <vector>

using namespace std;

int calculate_dollars(char* dict[], int length){
    int count = 1;
    int dollars = 0;
    while(count < length){
        if(*dict[count] > *dict[count - 1]){
            dollars++;                 
        }
        count++; 
    }
    return dollars;
}

int main(){
    FILE* data = fopen("./moist_cards.data", "r");  
    char* p_line = new char[1024];
    fgets(p_line, 1024, data);
    int t = atoi(p_line);
    for(int i = 0; i < t; ++i){
        fgets(p_line, 1024, data);
        int n = atoi(p_line);
        char* dict[n]; 
        int x = 0;
        while(x < n){
            fgets(p_line, 1024, data);
            dict[x] = p_line;
            x++;
        }
        int dol = calculate_dollars(dict, n);
        printf("Case:#%d:%d\n", i, dol);
    }
    fclose(data);
    return 0;
}
