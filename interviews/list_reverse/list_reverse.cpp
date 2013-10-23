#include <iostream>

using namespace std;

struct node{
    node* next;
    int data; 
}_node;

void reverse_list(node* head){
    node* p, * q; 
    p = head->next;
    head->next = NULL;
    while(NULL != p){
        q = p->next;
        p->next = head->next; 
        head->next = p;
        p = q;
    }
}

void reverse_list_two(node* head){
    node* p1 = head;
    node* p2 = p1->next;
    node* p3 = p2->next;
    p1->next = NULL;
    while(NULL != p3){
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p2->next;
    }
    p2->next = p1;
    head = p2;
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
    while(now != NULL){
        cout << now->data << ":" << &now << " ";
        now = now->next; 
    }
    cout << endl;
    //reverse
    //reverse_list(head);
    reverse_list_two(head);
    now = head;
    while(now != NULL){
        cout << now->data << ":" << &now << " ";
        now = now->next; 
    }
    cout << endl;
    delete now;
    return 0;
}
