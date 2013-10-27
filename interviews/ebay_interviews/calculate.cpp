#include <iostream>
#include <string>
#include <map>

using namespace std;
template<class T>
struct node{
    node* p_node;
    node* left_node;
    node* right_node;
    T data;
};

void init_operation(map<char, int> operation){
}

void travel_tree(node* root){
    if(root->left_node){
        cout << root->left_node->data << endl;
        travel_tree(root->left_node);
    }else if(root->right_node){
        travel_tree(root->right_node);
    }else return;
}

int main(int argc, const char* argv[]){
    string express(argv[1]); 
    int c = 0, length = express.size();
    node* root = new node;
    root->p_node = NULL;
    map<char, ddnt> operation;
    //init_operation(operation);
    while(c < length){
        if(operation[express[c]]){
            node* curr = new node;
            curr->parent = root;
            curr->left_node = express[c] - '0';
            curr->right_node = express[c] - '0';
        }
        c++;
    }

    return 0;
}
