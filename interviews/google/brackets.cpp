#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
    char* data = new char[argc - 1];
    char* p_data = data;
    strcpy(data, argv[1]);
    int stack[argc];
    int* top = stack;
    while(*p_data != '\0'){
        if(*p_data == '('){
            *top = 1;
            top++;
        }
        else if(*p_data == ')'){
            if(top == stack){
                printf("brackets could not matched\n");
                return 0;
            }
            *top = 0;
            top--;
        }
        p_data++; 
    } 
    if(top != stack){
        printf("brackets could not matched\n");
    }else printf("brackets matched\n"); 
    return 0;
}
