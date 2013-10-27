#include <iostream>

using namespace std;
void match_recursion(char* p_data, int* top, int* stack){
    if('(' == *p_data){
        *top = 1;
        p_data++;
        top++;
        match_recursion(p_data, top, stack);
    }else if(')' == *p_data){
        *top = 0;
        p_data++;
        top--;
        match_recursion(p_data, top, stack);
    }else if('\0' == *p_data) return; 
    else{
        p_data++;
        match_recursion(p_data, top, stack); 
    }
}

int main(int argc, const char* argv[]){
    char* data = new char[argc - 1];
    char* p_data = data;
    strcpy(data, argv[1]);
    int* stack = new int[argc];
    int* top = stack;
    match_recursion(p_data, top, stack);
    if(top == stack) printf("brackets matched\n");
    else printf("brackets could not matched\n");
    return 0;
}
