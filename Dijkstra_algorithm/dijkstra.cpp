#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct node{
    int node_id;
}_node;

struct vertex{
    node* from_node;
    node* to_node;
    double cost;
}_vertex;

void dijkstra_search(vector<node*>*, vector<vertex*>*, vector<int>*, node*);
void build_graph(vector<node*>*, vector<vertex*>*);

int main(int argc, const char** argv)
{
    vector<node*>* p_nodes = new vector<node*>;
    vector<vertex*>* p_vertexes = new vector<vertex*>;
    vector<int>* p_route = new vector<int>;
    node* p_end = new node;
    p_end = *(p_nodes->end());

    dijkstra_search(p_nodes, p_vertexes, p_route, p_end);

    for(vector<int>::iterator i = p_route->begin(); i != p_route->end(); ++i) printf("%d ", *i);
    return 0;
}

void build_graph(vector<node*>* p_nodes, vector<vertex*>* p_vertexes)
{
    node* n_0 = new node;      
    node* n_1 = new node;
    node* n_2 = new node;
    node* n_3 = new node;
    node* n_4 = new node;

    n_0->node_id = 0;
    n_1->node_id = 1;
    n_2->node_id = 2;
    n_3->node_id = 3;
    n_4->node_id = 4;

    vertex* v_0 = new vertex;
    vertex* v_1 = new vertex;
    vertex* v_2 = new vertex;
    vertex* v_3 = new vertex;
    vertex* v_4 = new vertex;
    vertex* v_5 = new vertex;
    vertex* v_6 = new vertex;
    vertex* v_7 = new vertex;
    vertex* v_8 = new vertex;
    
    v_0->from_node = n_0;
    v_0->to_node = n_1;
    v_0->cost = 1.0; 
} 

void dijkstra_search(vector<node*>* p_nodes, vector<vertex*>* p_vertexes, vector<int>* p_route, node* p_end)
{
    vector<node*>::iterator n = p_nodes->begin(); 
    double tmp_cost = 0.0;
    node* next_step = new node;
    while(*n != p_end)
    {
        next_step = *n;
        vector<vertex*> tmp_vec;
        for(vector<vertex*>::iterator v = p_vertexes->begin(); v != p_vertexes->end(); ++v)
        {
            if((*v)->from_node == (*n)) tmp_vec.push_back(*v);
        }

        for(vector<vertex*>::iterator i_tmp = tmp_vec.begin(); i_tmp != tmp_vec.end(); ++i_tmp)
        {
            if(tmp_cost <= (*i_tmp)->cost)
            {
                tmp_cost = (*i_tmp)->cost;
                next_step = (*i_tmp)->to_node;
            }
        }

        p_route->push_back((*n)->node_id);
        n++; 
    }
}

