#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    cout << "\n vector size is : " << v.size() << endl;
    vector<int>::iterator p = v.begin();
    while(p != v.end())
    {
        cout << " " << (*p) << endl; 
        p++;
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(6);
    v.push_back(3);
    vector<int>::iterator itor, itor2;
    itor = v.begin();
    for(itor = v.begin(); itor != v.end();){
        if(6 == *itor){
            itor2 = itor;
            //v.erase(itor2);
        }
        itor++;
    }
    print(v);
    return 0;
}
