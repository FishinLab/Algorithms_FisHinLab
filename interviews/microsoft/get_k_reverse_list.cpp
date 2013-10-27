#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
}_node;

int main(int argc, const char* argv[]){
    node* head = new node;
    head->next = NULL;
    node* curr = head;
    for(int i = 1; i < argc; ++i){
        node* new_one = new node;
        new_one->data = atoi(argv[1]);
        curr->next = new_one;
        curr = curr->next;
    } 
    curr = head;
    int length = 0;
    while(curr != NULL){
        length++;
        curr = curr->next;
    }
    int k = 1;
    //scanf("%d\n", &k);
    k = length - k + 1;
    curr = head;
    while(k > 0){
        curr = curr->next;
        k--;
    }
    cout << curr->data << endl;
    return 0;
}
