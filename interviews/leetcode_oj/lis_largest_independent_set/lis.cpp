#include <iostream>
#include <vector>

using namespace std;

struct tree_node{
    tree_node* p_left;
    tree_node* p_right;
    int val;
}_tree_node;

void lis(tree_node* root, vector<tree_node*> *record){
    tree_node* tmp_left = new tree_node;
    tree_node* tmp_right = new tree_node;
    if(root->p_left) tmp_left = root->p_left; 
    if(root->p_right) tmp_right = root->p_right; 
    if(tmp_left->p_left || tmp_left->p_right){
        record->push_back(root);                
        lis(tmp_left, record);
    }else if(tmp_right->p_left || tmp_right->p_right){
        record->push_back(root);                
        lis(tmp_right, record);
    }else return;
}

int main(int argc, const char* argv[]){
    tree_node* root = new tree_node;
    tree_node* n_20 = new tree_node;
    tree_node* n_30 = new tree_node;
    tree_node* n_40 = new tree_node;
    tree_node* n_50 = new tree_node;
    tree_node* n_60 = new tree_node;
    tree_node* n_70 = new tree_node;
    tree_node* n_80 = new tree_node;

    root->p_left = n_20;
    root->p_right = n_30;
    root->val = 10;

    n_20->p_left = n_40;
    n_20->p_right = n_50;
    n_20->val = 20;

    n_30->p_left = NULL;
    n_30->p_right = n_60;
    n_30->val = 30;

    n_40->p_left = NULL;
    n_40->p_right = NULL;
    n_40->val = 40;

    n_50->p_left = n_70;
    n_50->p_right = n_80;
    n_50->val = 50;

    n_60->p_left = NULL;
    n_60->p_right = NULL;
    n_60->val = 60;

    n_70->p_left = NULL;
    n_70->p_right = NULL;
    n_70->val = 70;

    n_80->p_left = NULL;
    n_80->p_right = NULL;
    n_80->val = 80;
    
    vector<tree_node*>* record = new vector<tree_node*>;
    lis(root, record);
    for(vector<tree_node*>::iterator iv = record->begin(); iv != record->end(); ++iv){
        cout << (*iv)->val << " ";
    }
    cout << endl;

    return 0;
}
