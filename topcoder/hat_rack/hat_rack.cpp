#include <iostream>
#include <vector>

using namespace std;

struct hat_rack
{
    hat_rack* h_parent;  
    pair<hat_rack*> h_children; 
    int level;
};

hat_rack* build_tree(vector<int>*, vector<int>*); 

int main(int argc, const char* argv[])
{
    vector<int>* p_parent = new vector<int>;
    vector<int>* p_children = new vector<int>;
    hat_rack* p_hat_rack = build_tree(p_parent, p_children);
    return 0; 
}

hat_rack* build_tree(vector<int>* p_parent, vector<int>* p_children)
{
    hat_rack* p_hat_rack = new p_hat_rack;
    int length = p_parent->begin();
    int count = 0; 
    do
    {
        if(!hat_rack)
        {
            hat_rack->level = 0;
            hat_rack->h_parent = NULL;
        }
    }while(count < length);
    return p_hat_rack;
}
