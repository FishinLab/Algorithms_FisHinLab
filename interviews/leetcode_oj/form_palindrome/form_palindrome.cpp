#include <iostream>

using namespace std;

int get_diff_num(string one, string two){
    //if(!one.size() || !two.size()) return one.size() + two.size() + 1;
    int diff = 0;
    for(int i = 0; i < one.size(); ++i){
        for(int j = 0; j < two.size(); ++j){
            if(one[i] != two[j]) diff++;
        }
    }
    return diff;
}

int form_palindrome(string& data){
    int length = data.size();
    if(length == 1) return length;
    int c = 1, sum = length - 1, tmp_sum = 0; 
    while(c < length - 1){
        string one(data.substr(0, c));
        string two(data.substr(c + 1, length));
        cout << one << " " << two << endl;
        tmp_sum = get_diff_num(one, two);
        if(sum >= tmp_sum) sum = tmp_sum;
        c++;
    }
    return sum;
}

int main(int argc, const char* argv[]){
    string data(argv[1]);
    int sum = form_palindrome(data);
    printf("%d\n", sum);
    return 0;
}
