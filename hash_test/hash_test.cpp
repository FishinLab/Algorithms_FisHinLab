#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using namespace std;

#ifndef MAX_DATA
#define MAX_DATA 10000000
#endif

#ifndef LEN
#define LEN 1000
#endif

#ifndef HASH_NUM
#define HASH_NUM 1021
#endif

void hash_func(const int data, vector<list<int> >* p_store)
{
    int store_addr = data % HASH_NUM;
    vector<list<int> >::iterator i_s = p_store->begin();
    if((*i_s).empty())
    {
        list<int> tmp;
        tmp.push_back(data);
        *i_s = tmp;
    }
    else
    {
        (*i_s).push_back(data); 
    }
}

int main(int argc, const char* argv[])
{
    list<int> l_store(0, 1);
    vector<list<int> >* hash_storage = new vector<list<int> >;
    for(int i = 0;i < HASH_NUM; ++i)
    {
        hash_storage->push_back(l_store);
    }
    int data =  0;
    argv[1] ? data = atoi(argv[1]) : data = MAX_DATA; 

    hash_func(data, hash_storage);
   
    for(vector<list<int> >::iterator i_s = hash_storage->begin(); i_s != hash_storage->end(); ++i_s)
    {
        for(list<int>::iterator l_s = (*i_s).begin(); l_s != (*i_s).end(); ++l_s)
        {
            cout << data << " is stored in address " << &i_s << endl;
        }
    }

    return 0;
}
