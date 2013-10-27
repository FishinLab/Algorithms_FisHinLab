#include <iostream>
#include <stack>

using namespace std;

struct node{
    node* p_left;
    node* p_right;
    int val;
}_node;

void get_nearest_parent(node* root, node* n_one, node* n_two){
    if(n_one == root) return n_one;
    if(n_two == root) return n_two;
    stack<node*> path_stack;
    DFS(root, path_stack);
    while(path_stack.empty() == false){
        node* tmp_node = path_stack.pop();
        if(has_child(tmp_node, n_two)) printf("has found the parent node %d\n", tmp_node->val);
    }
}

void DFS(node* root, stack<node*> &path_stack){
    if(root->p_left == NULL) return;
    if(root->p_right == NULL) return;
    path_stack.push(root);
    DFS(root->p_left, path_stack);
    DFS(root->p_right, path_stack);
}

bool has_child(node* root, node* n_child){
    if(root->p_left == n_child) return true;
    if(root->p_right == n_child) return true;
    has_child(root->p_left, n_child);
    has_child(root->p_right, n_child);
    return false;
}
