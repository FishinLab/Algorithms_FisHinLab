#include <iostream>
#include <vector>

using namespace std;

struct hat_rack_tree
{
    hat_rack_tree* p_parent;
    pair<hat_rack_tree*> p_children;
    int level;
    int num_child;
    int data;
};

int build_tree(vector<int>*, vector<int>*);
hat_rack_tree* get_knob(int, hat_rack_tree*);

int main(int argc, const char* argv[])
{
    vector<int>* v_parent = new vector<int>;
    vector<int>* v_kids = new vector<int>;
    int result = build_tree(v_parent, v_kids); 
    cout << (2 << result) << endl;
    return 0;
}

int build_tree(vector<int>* v_parent, vector<int>* v_kids)
{
    hat_rack_tree* p_hat_rack = new hat_rack_tree; 
    hat_rack_tree* p_head = p_hat_rack;
    int index = 1;
    int count = 0;
    int length = v_parent->size();
    do
    {
        p_hat_rack->data = (*v_parent)[count];
        if((*v_parent)[count] == (*v_parent)[count + 1])
        {
            p_hat_rack->num_child = 2;
            index++;
        }
        else
        {
            p_hat_rack->num_child = 1;
        }
        count < 3 ? p_hat_rack->p_parent = NULL : p_hat_rack->p_parent = get_knob((*v_parent)[count], p_head);
        count++; 
    }while(count < length);
    return index;
}

hat_rack_tree* get_knob(int data, hat_rack_tree* p_head)
{
    hat_rack_tree* p_tmp = p_head;            
    while(0 != p_tmp->num_child)
    {
        if(2 == p_tmp->num_child)
        {
            if(((p_tmp->p_children).first)->data == data)
            {
                return (p_tmp->p_children).first; 
            }
            else if(((p_tmp->p_children).second)->data == data)
            {
                return (p_tmp->p_children).second 
            }
            else get_knob(data, p_tmp);
        }
        else if(1 == p_tmp->num_child)
        {
            if(((p_tmp->p_children).first)->data == data)
            {
                return (p_tmp->p_children).first; 
            }
            else p_tmp = (p_tmp->p_children).first;
        }
        else break;
    }

}
