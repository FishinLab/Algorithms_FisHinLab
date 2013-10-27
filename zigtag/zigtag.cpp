#include <iostream>
#include <vector>

using namespace std;

void generate_init_mat(vector<vector<int>* >*, int);
void generate_zig_mat(vector<vector<int>* >*);

int main(int argc, const char* argv[])
{
    vector<vector<int>* >* zig_mat = new vector<vector<int>* >;
    int data_scale = atoi(argv[1]);
    (*(*zig_mat)[0])[0] = 1;
    //generate_init_mat(zig_mat, data_scale);
    //generate_zig_mat(zig_mat);
    for(vector<vector<int>* >::iterator i = zig_mat->begin(); i != zig_mat->end(); ++i)
    {
        for(vector<int>::iterator j = (*i)->begin(); j != (*i)->end(); ++j)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}

void generate_init_mat(vector<vector<int>* >* p_mat, int data_scale)
{
    vector<vector<int>* >* p_tmp_mat = new vector<vector<int>* >;
    for(int i = 1; i < data_scale; ++i)
    {
        for(int j = 1; j < data_scale; ++j)
        {
        }
    }
}
