#include <iostream>
#include <stack>

using namespace std;
struct node{
    int val;
    node* left;
    node* right;
}_node;

void DFS(node* root, stack<node*> &rec_stack){
    if(root->left == NULL && root->right == NULL){
        rec_stack.push(root);
        return;
    }
    else if(root->left){
        rec_stack.push(root->left);
        DFS(root->left, rec_stack);
    }else if(root->right){
        rec_stack.push(root->right);
        DFS(root->right, rec_stack);
    } 
}

void plus_down(node* root, int target){
    stack<node*> rec_stack;
    DFS(root, rec_stack); 
    int sum = 0;
    while(rec_stack.empty()){
        printf("%d ", rec_stack.top()->val);
        rec_stack.pop();
    }
    printf("\n");
}

int main(int argc, const char* argv[]){
    int target = atoi(argv[1]);

    node* root = new node;
    node* n_1 = new node;
    node* n_2 = new node;
    node* n_3 = new node;
    node* n_4 = new node;
    node* n_5 = new node;
    node* n_6 = new node;
    node* n_7 = new node;
    node* n_8 = new node;

    root->val = 5;
    n_1->val = 4;
    n_2->val = 8;
    n_3->val = 11;
    n_4->val = 13;
    n_5->val = 4;
    n_6->val = 7;
    n_7->val = 2;
    n_8->val = 1;

    root->left = n_1;
    root->right = n_2;
    
    n_1->left = n_3;
    n_1->right = NULL;
    
    n_2->left = n_4;
    n_2->right = n_5;

    n_3->left = n_6;
    n_3->right = n_7;

    n_4->left = NULL;
    n_4->right = NULL;

    n_5->left = NULL;
    n_5->right = n_8;

    n_6->left = NULL;
    n_6->right = NULL;

    n_7->left = NULL;
    n_7->right = NULL;

    n_8->left = NULL;
    n_8->right = NULL;

    plus_down(root, target);
    return 0;
}
