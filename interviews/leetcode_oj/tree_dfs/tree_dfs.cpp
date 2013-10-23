#include <iostream>
#include <vector>

using namespace std;

struct tree_node{
    tree_node* p_left;
    tree_node* p_right;
    int val;
}_tree_node;

void dfs(tree_node* root, tree_node* node){
    if(root == NULL) return;
    if(root == node){
        printf("%d\n", root->val);
        return;
    }else{
        dfs(root->p_left, node);
        dfs(root->p_right, node);
    }
}

void has_child(tree_node* root, tree_node* node){
    if(root == NULL) return;
    if(root == node){
        printf("child node found, %d\n", root->val);
        return;
    }else{
        has_child(root->p_left, node);
        has_child(root->p_right, node);
    }
}

void bfs(tree_node* root, vector<tree_node*>* queue){
    while(root->p_left || root->p_right){
        if(root->p_left) queue->push_back(root->p_left);
        if(root->p_right) queue->push_back(root->p_right);
        if(root->p_left) bfs(root->p_left, queue);
        if(root->p_right) bfs(root->p_right, queue);
    }
    return;
}

int main(int argc, const char* argv[]){
    tree_node* root = new tree_node;
    root->val = 0;
    tree_node* node_1 = new tree_node;
    tree_node* node_2 = new tree_node;
    tree_node* node_3 = new tree_node;
    tree_node* node_4 = new tree_node;
    tree_node* node_5 = new tree_node;
    tree_node* node_6 = new tree_node;

    node_1->val = 1;
    node_2->val = 2;
    node_3->val = 3;
    node_4->val = 4;
    node_5->val = 5;
    node_6->val = 6;

    root->p_left = node_1;
    root->p_right = node_2;

    node_1->p_left = node_3;
    node_1->p_right = NULL;

    node_2->p_left = node_4;
    node_2->p_right = node_5;

    node_3->p_left = NULL;
    node_3->p_right = NULL;

    node_4->p_left = NULL;
    node_4->p_right = NULL;

    node_5->p_left = NULL;
    node_5->p_right = NULL;

    node_6->p_left = NULL;
    node_6->p_right = NULL;

    vector<tree_node*>* queue = new vector<tree_node*>;

    dfs(root, node_3); 
    has_child(root, node_4);
    bfs(root, queue);
    
    for(vector<tree_node*>::iterator it = queue->end(); it != queue->begin(); ++it){
        cout << (*it)->val; 
    }
    cout << endl;

    return 0;
}
