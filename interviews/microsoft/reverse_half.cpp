#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
}_node;

void reverse_half(node* head){
    node* p = head->next;
    node* s = head->next;
    head->next = NULL; 
    while(p != NULL){
        node* r = p;
        p = p->next;
        node* q = p->next;
        p->next = head->next;
        head->next = p;
        r->next = q;
        p = q;
    }
    p = head->next;
    while(s != NULL){
        node* r = p;
        p = p->next;
        node* q = s->next;
        s->next = p;
        r->next = s;
        s = q;
    }
}

int main(int argc, const char* argv[]){
    node* head = new node;
    node* tmp = head;
    for(int i = 1; i < argc; ++i){
        node* new_one = new node;
        new_one->data = atoi(argv[i]);
        tmp->next = new_one;
        tmp = tmp->next;
    }
    reverse_half(head);
    tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    delete head, tmp;
    return 0;
}
