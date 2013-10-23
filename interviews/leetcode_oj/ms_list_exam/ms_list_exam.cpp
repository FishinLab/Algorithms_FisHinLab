#include <iostream>

using namespace std;

struct node{
    node* next;
    int val;
}_node;

node* find_last(node* head){
    node* curr = head;
    while(curr->next){
        curr = curr->next;
    }
    return curr;
}

int get_list_length(node* head){
    int length = 0;
    node* curr= head;
    while(curr){
        length++;
        curr = curr->next;
    }
    return length;
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

    //output source data
    curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }

    //main operations 
    int list_len = get_list_length(head);    
    int c = list_len / 2;
    node* p = head->next, * r = head;
    while(c > 0){
        r = p;
        p = p->next;
        c--;
    }
    r->next = NULL;
    curr = head->next;
    r = head;
    c = list_len / 2;
    while(c > 0){
        r = curr;
        curr = curr->next;
        node* q = find_last(p);
        r->next = q;
        q->next = curr;
        c--;
    }

    //output destination data
    curr = head;
    while(curr){
        cout << endl << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    delete head;
    delete curr;
    return 0;
}
