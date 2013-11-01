#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct node{
    int val;
    node* left;
    node* right;
}_node;

void get_number(node* root, vector<int> &rec, int sum){
    if(NULL == root->left && NULL == root->right){
        int c = 0;
        for(vector<int>::iterator ir = rec.end(); ir != rec.begin(); ir--){
            sum += ((*ir) * (10 ^ c));
            cout << *ir << " " << sum << endl;
            c++;
        }
        return;
    }else{
        rec.push_back(root->val);
        if(root->left){
            rec.push_back(root->left->val);
            get_number(root->left, rec, sum);
        }else if(root->right){
            rec.push_back(root->right->val);
            get_number(root->right, rec, sum);
        }else return; 
    }
}

int main(int argc, const char* argv[]){
    node* root = new node;
    node* child_0 = new node;
    node* child_1 = new node;
    root->val = 1;
    root->left = child_0;
    root->right = child_1;

    child_0->val = 2;
    child_1->val = 3;

    child_0->left = NULL;
    child_1->left = NULL;
    child_0->right= NULL;
    child_1->right= NULL;

    vector<int> rec;
    int sum = 0;
    get_number(root, rec, sum);
    cout << "sum_root_to_leaf_numbers: " << sum << endl;
    return 0;
}
