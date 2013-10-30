#include <iostream>
#include <string>

using namespace std;

void edit_distance(string word_one, string word_two){
    int edit_len = word_one.size() - word_two.size(), res = 0;

    if(0 == edit_len){
        for(int i = 0; i < word_one.size(); ++i){
            if(word_one[i] != word_two[i]) res++;
        }  
    }else if(0 > edit_len){
        for(int i = 0; i < word_two.size(); ++i){
            if(word_one[i] != word_two[i]){
                word_one.insert(i, word_two, i, 1);
                res++;
            }
        }
        for(int i = 0; i < word_one.size(); ++i){
            if(word_one[i] != word_two[i]) res++;
        }  
    }else{
        for(int i = 0; i < word_two.size(); ++i){
            if(word_one[i] != word_two[i]){
                word_one.erase(i, 1);
                res++;
            }
        }
        for(int i = 0; i < word_one.size(); ++i){
            if(word_one[i] != word_two[i]) res++;
        } 
    }
    cout << "edit_distance: " << res << endl;
}

int main(int argc, const char* argv[]){
    string word_one(argv[1]);
    string word_two(argv[2]);

    edit_distance(word_one, word_two);

    return 0;
}
