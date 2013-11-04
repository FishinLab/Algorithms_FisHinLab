#include <iostream>

using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node* next;
    node(val, right, left, next);
};

node* init(int val, node* right, node* left, node* next){
    node* n = new node;
    n->val = val;
    n->right = right;
    n->left = left;
    n->next = NULL;
}

void populate_next_pointers(node* root){
    if(NULL == root->left && NULL == root->right) return;
    else{
        root->left->next = root->right;        
        root->left->right->next = root->right->left;
        populate_next_pointers(root->left);
        populate_next_pointers(root->right);
    }
}

void close(node* root){
    if(NULL == root) return;
    else{
        root->right->next = NULL;
        close(root->right);
    }
}

int main(int argc, const char* argv[]){
    /*
    node* n_1;
    node* n_2;
    node* n_3;
    node* n_4;
    node* n_5;
    node* n_6;
    node* n_7;

    n_1 = init(0, n_1, n_2, NULL);
    n_2 = init(0, n_4, n_5, NULL);
    n_3 = init(0, n_6, n_7, NULL);
    n_4 = init(0, NULL, NULL, NULL);
    n_5 = init(0, NULL, NULL, NULL);
    n_6 = init(0, NULL, NULL, NULL);
    n_7 = init(0, NULL, NULL, NULL);
    */
    node* n_7(0, NULL, NULL, NULL);
    node* n_6(0, NULL, NULL, NULL);
    node* n_5(0, NULL, NULL, NULL);
    node* n_4(0, NULL, NULL, NULL);
    node* n_3(0, n_6, n_7, NULL);
    node* n_2(0, n_4, n_5, NULL);
    node* n_1(0, n_2, n_3, NULL);

    populate_next_pointers(n_1);
    n_1->next = NULL;
    close(n_1);

    return 0;
}
