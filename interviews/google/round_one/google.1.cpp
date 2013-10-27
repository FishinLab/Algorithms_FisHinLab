#include <iostream>
#include <map>
#include <vector>

using namespace std;

void read_number(char* num, int t){
    printf("Case #%d: ", t + 1);
    while(*num != '\0'){
        if(*num == *(num + 1)){
            printf("double ");
            num++;
        } 
        if(*num == *(num + 1) == *(num + 2)){
            printf("double ");
            num++;
        } 
        switch(*num - '0'){
            case 0:
                printf("zero ");
                break;
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
        }
        num++;
    }
}

int main(){
    FILE* data = fopen("/Users/kyokukyokujinnan/Downloads/A-small-attempt4.in.txt", "r");
    char* p_line = new char[1024];
    fgets(p_line, 1024, data);
    int T = atoi(p_line); 
    for(int i = 0; i < T; ++i){
        int x;
        fgets(p_line, 1024, data);
        for(x = 0; x < strlen(p_line) && p_line[x] != ' '; ++x);
        x++;
        char* num = new char[12];
        char* format = new char[8];
        strncat(num, (const char*)p_line, x);
        p_line += x;
        x = 0;
        while(*p_line != '\0'){
            format[x] = *p_line; 
            x++;
            p_line += 2;
        }
        for(x = 0; x < strlen(format); ++x){
            char* sep_num = new char[format[x]];
            strncat(sep_num, (const char*)num, format[x]);
            read_number(sep_num, i);
            //cout << sep_num << endl;
            printf("\n");
        }
    }
    return 0;
}
