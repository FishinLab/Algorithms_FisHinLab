#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void generate_parentheses(vector<string> &now, string s, int left, int right, int len){
    if(left == len){
        now.push_back(s.append(len - right, ')'));
        return;
    }    
    if(left > right) generate_parentheses(now, s + ')', left, right + 1, len);
    generate_parentheses(now, s + '(', left + 1, right, len);
}

int main(int argc, const char* argv[]){
    int n = atoi(argv[1]);
    vector<string> now;

    generate_parentheses(now, "", 0, 0, n);
    
    for(vector<string>::iterator is = now.begin(); is != now.end(); ++is){
        cout << *is << endl;
    }
    return 0;
}
