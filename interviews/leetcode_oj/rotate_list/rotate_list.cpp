#include <iostream>

using namespace std;

struct node{
    node* next;
    int val;
}_node;

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
    curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    int k = 0,c = 0;
    node* p = head->next;
    node* r = head;
    scanf("%d", &k);
    while(c != k){
        r = p;
        p = p->next;
        c++;
    }
    curr = head->next;
    head->next = p;
    r->next = NULL;
    r = p;
    while(r->next){
        r = r->next;        
    }
    r->next = curr;

    curr = head;
    while(curr){
        cout << endl << curr->val << " ";
        curr = curr->next;    
    }
    cout << endl;

    delete head;
    return 0;
}
