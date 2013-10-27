#include <iostream>

using namespace std;

struct node{
    node* next;
    int data;
}_node;

void swap_nth_node(node* head, int n){
    if(head->next == NULL) return;
    node* p = head->next;
    node* r = head;
    node* q = head->next;
    while(n > 0){
        r = r->next;
        p = p->next;
        n--;
    }
    r->next = p->next;
    p->next = head->next;
    head->next = p;
    q->next = r->next;
    r->next = q;
}

int main(int argc, const char* argv[]){
    node* head = new node;
    head->data = 0;
    head->next = head;
    node* now = head;
    for(int i = 1; i < argc; ++i){
        node* curr = new node;
        head->next = curr;
        curr->next = NULL;
        curr->data = atoi(argv[i]);
        head = head->next;
    }
    head = now;
    int n = argc / 2;
    swap_nth_node(head, n);
    while(now != NULL){
        cout << now->data << " ";
        now = now->next;
    }
    cout << endl;
    delete now;
    return 0;
}
