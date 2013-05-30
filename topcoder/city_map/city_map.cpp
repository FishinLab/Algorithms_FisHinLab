#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string get_legend(vector<string>*, vector<int>*);

int main(int argc, const char* argv[])
{
    vector<string> test_data(("M....M"), ("...R.M"), ("R..R.R"));
    vector<string>* p_test_data = &test_data;
    vector<int> pois(3,4); 
    vector<int>* p_pois = &pois;
    string result = get_legend(p_test_data, p_pois);
    cout << result << endl;
    return 0;
}

string get_legend(vector<string>* p_city_map, vector<int>* p_pois)
{
    string result = "";
    map<const char, int>* data_sorted = new map<const char, int>;
    for(vector<string>::iterator i = p_city_map->begin(); i != p_city_map->end(); ++i)
    {
        (*data_sorted)[*i]++; 
    }
    for(vector<int>::iterator i = p_pois->begin(); i != p_pois->end(); ++i)
    {
        for(map<const char, int>::iterator m = data_sorted->begin(); m != data_sorted->end(); ++m)
        {
            if((*m).second == *i)
            {
                string tmp(&((*m).first));
                result += tmp; 
            }
        }
    }
    return result;
}
