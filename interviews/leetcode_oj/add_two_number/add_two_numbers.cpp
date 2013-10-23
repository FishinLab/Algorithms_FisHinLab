#include <iostream>

using namespace std;

struct node{
    node* next;
    int val;
}_node;

void add_two_numbers(node* one, node* two){
    node* head = new node;
    node* curr = new node;
    int tmp_rec = 0;
    node* p = one->next,* q = two->next;
    while(p && q){
        node* new_one = new node;
        new_one->val = (p->val + q->val) % 10 + tmp_rec;
        tmp_rec = (int)((new_one->val + p->val + q->val) / 10);
        p = p->next;
        q = q->next;
        curr->next = new_one;
        curr = new_one;
    }
    curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(int argc, const char* argv[]){
    node* one = new node;
    node* two = new node;
    int one_data[3] = {2, 4, 3}; 
    int two_data[3] = {5, 6, 4};
    node* curr_one = new node;
    curr_one = one;
    for(int i = 0; i < 3; ++i){
        node* new_one = new node;
        new_one->val = one_data[i]; 
        curr_one->next = new_one;
        curr_one = new_one;
    }
    node* curr_two = new node;
    curr_two = two;
    for(int i = 0; i < 3; ++i){
        node* new_one = new node;
        new_one->val = two_data[i]; 
        curr_two->next = new_one;
        curr_two = new_one;
    }
    add_two_numbers(one, two);
    return 0;
}
