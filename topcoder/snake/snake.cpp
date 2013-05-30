#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void show_status(vector<vector<int> >*);
void init_mat(vector<vector<int> >* , int, int);
void refresh(vector<vector<int> >* , int, pair<int, int>, pair<int, int>);
void move(vector<vector<int> >* );

int main(int argc, const char* argv[])
{
    int init_snake_length = argv[1];
    int matrix_size = argv[2];

    vector<vector<int> >* mat = new vector<vector<int> >;
    init_mat(mat, matrix_size, init_snake_length);

    while(true)
    {
        refresh(mat);
        move(mat);
    }
}
void init_mat(vector<vector<int> >* mat, int matrix_size, int init_snake_length)
{
    for(int i = 0; i < matrix_size; ++i)
    {
        for(int j = 0; j < matrix_size; ++j)
        {
            (*mat)[i][j] = 0;
        }
    }
    int c = 0;
    while(c < init_snake_length)
    {
        (*mat)[0][c] = 1;
        c++;
    }
}
void refresh(vector<vector<int> >* mat, int snk_size, pair<int, int> head, pair<int, int> food)
{
         
}
void move(vector<vector<int> >* mat)
{
    
}
void show_status(vector<vector<int> >* mat)
{
    for(vector<vector<int> >::iterator i = mat->begin(); i != mat->end(); ++i)
    {
        for(vector<int>::iterator j = i->begin(); j != i->end(); ++j)
        {
            cout << *j;
        }
        cout << endl;
    }
}
