/*
 *  revert list:
 *  h->1->2->3->4->5->6->7->8
 *  h->3->2->1->6->5->4->7->8
 * */
#include <iostream>

using namespace std;
struct node{
    int val;
    node* next;
}_node;

void revert_list(node* head){
    node* p = head->next;
    node* q = p->next;
    head->next = NULL;
    while(q){
        head->next = p->next;
        p->next = q;
        head->next = p;
        p = p->next;
        q = p->next;
    }
}

void revert(node* head, int length){
    int c = 0;
    node* h = head->next;
    while(c < length % 3){
        node* p = h;

        for(int i = 0; i < 2; ++i) p = p->next; 
        node* q = p->next;
        //h->next = NULL;
        //p->next = NULL;
        node* ph = h; 
        //ph->next = p;
        revert_list(ph);
        p = ph->next;

        for(int i = 0; i < 3; ++i) p = p->next; 
        p->next = q;
        h->next = ph->next;
        ph->next = NULL;
    }
}

int main(int argc, const char* argv[]){
    int length = argc - 1;
    node* head = new node;
    node* curr = head;
    for(int i = 0; i < length; ++i){
        node* new_one = new node;
        new_one->val = atoi(argv[i + 1]);
        curr->next = new_one;
        curr = new_one;
    }
    
    revert(head, length);

    curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
