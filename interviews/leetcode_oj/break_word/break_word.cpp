#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool in_dict(string str, vector<string> dict){
    for(vector<string>::iterator id = dict.begin(); id != dict.end(); ++id){
        if(*id == str) return true;
    }
    return false;
}

void break_word(string data, vector<string> dict){
    int length = data.size(), c = 0;
    while(c <= length){
        string pre_str = data.substr(0, c); 
        if(in_dict(pre_str, dict)){
            cout << pre_str << " ";
            break_word(data.substr(c, length), dict);
        }
        c++;
    }
    cout << endl;
}

int main(int argc, const char* argv[]){
    vector<string> dict;
    for(int i = 0; i < argc - 1; ++i){
        dict.push_back(string(argv[i + 1]));
    }
    string data(argv[argc - 1]);
    break_word(data, dict);
    return 0; 
}
