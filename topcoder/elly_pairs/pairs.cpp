#include <iostream>
#include <list>

using namespace std;

int match_pairs(list<int>*, list<int>*);

int main(int argc, const char* argv[])
{
    list<int>* p_src_data = new list<int>;
    for(int i = 1; i < argc; ++i)
    {
        p_src_data->push_back(atoi(argv[i]));
    }
    p_src_data->sort();
    list<int>* p_order = &p_src_data;
    list<int>* p_reverse = &(p_src_data->reverse());
    int result = match_pairs(p_order, p_reverse);
    cout << result << endl;
    return 0;
}

int match_pairs(list<int>* p_order, list<int>* p_reverse)
{
    int result = 0;  
    int length = p_order->size();
    list<int>::iterator i_head = p_order->begin();
    while(i_head != p_order->end())
    {
        *i_head = 
        i_head++; 
    }
    return result;
}
