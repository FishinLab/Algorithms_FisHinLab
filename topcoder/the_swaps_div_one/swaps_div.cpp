#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

void swaping(vector<int>*); 
double get_expection(vector<int>*);

int main(int argc, const char* argv[])
{
    int k = atoi(argv[2]);
    string str_data(argv[1]);     
    int data_scale = str_data.size();

    vector<int>* p_src_data = new vector<int>;     

    for(int i = 0; i < data_scale; ++i)
    {
        const char* tmp = &(str_data.c_str()[i]);
        p_src_data->push_back(atoi(tmp));
        //p_src_data->push_back(atoi(str_data.c_str()[i])); 
    }

    int count = 0;
    while(count < k)
    {
        swaping(p_src_data);
        count++;
    }
    double result = get_expection(p_src_data);
    cout << result << endl;
    return 0;
}

void swaping(vector<int>* p_src_data)
{
    int scale = p_src_data->size();
    srand(clock());
    pair<int, int> locations;
    locations.first = int(random()) % scale;
    locations.second = int(random()) % scale;
    int tmp = (*p_src_data)[locations.first];
    (*p_src_data)[locations.first] = (*p_src_data)[locations.second];
    (*p_src_data)[locations.second] = tmp;
}

double get_expection(vector<int>* p_src_data)
{
    double result = 0.0;
    for(vector<int>::iterator i = p_src_data->begin(); i != p_src_data->end(); ++i)
    {
        result += *i;
    }
    result = result / (p_src_data->size());
    return result;
}
