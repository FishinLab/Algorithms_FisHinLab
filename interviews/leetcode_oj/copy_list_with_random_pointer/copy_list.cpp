#include <iostream>
#include <time>

using namespace std;

struct node{
    node* next;
    node* random;
    int val;
}_node;

int main(int argc, const char* argv[]){
    node* head = new node;
    node* curr = new node;
    head->next = curr;
    for(int i = 0; i < argc; ++i){
        
    }
    return 0;
}
