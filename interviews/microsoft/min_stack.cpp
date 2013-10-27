#include <iostream>

using namespace std;

struct min_stack{
    int* data;
    int top;
}_min_stack;

void push(min_stack* stack, int data){
    stack->data[stack->top] = data;
    stack->top = stack->top + 1;
}

int pop(min_stack* stack){
    int result = stack->data[stack->top];
    stack->top = stack->top - 1;
    return result;
}


int get_stack_min(min_stack* stack){
    min_stack* tmp_stack = new min_stack;
    int min = pop(stack); 
    while(stack->top != NULL){
        push(tmp_stack, pop(stack));
        if(min >= tmp_stack->data[0]){ 
            min = tmp_stack->data[0]; 
        }
        top--; 
    }
    return min;
}
int main(int argc, const char* argv[]){
    min_stack* stack = new min_stack;
    for(int i = 1;i < argc; ++i){
        pop(stack, atoi(stack->data));
    }
    int result = get_stack_min(stack);
    printf("the min data is : %d\n", result);
    return 0;
}
