#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<pair<double, double> >* generate_computing_arr(vector<double>*);
double get_position(vector<double>*);

int main(int argc, const char* argv[])
{
    int data_scale = argc - 1;
    vector<double>* p_src_data = new vector<double>;
    for(int i = 0; i < argc; ++i)
    {
        p_src_data->push_back(atof(argv[i]));
    }
    vector<pair<double, double> >* p_res_data = generate_computing_arr(p_src_data); 
    double result = get_position(p_res_data);
    cout << result << endl;
    return 0;
}

vector<pair<double, double> >* generate_computing_arr(p_src_data)
{
    vector<pair<double, double> >* p_res = new vector<pair<double, double> >;
    for(vector<pair<double, double> >::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
        if(i == p_src_data->end()) 
        {
            pair<double, double> tmp_pair;
            tmp_pair.first = 0.0;
            tmp_pair.second = *i;
            p_res->push_back(tmp_pair);
        }
        else
        {
            
        }
    }
}
