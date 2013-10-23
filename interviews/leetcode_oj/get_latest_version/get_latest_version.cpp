#include <iostream>
#include <vector>

using namespace std;
#define MAX_LIMIT

void get_latest_version(vector<char*>* data, int length){
    if(length == 1) cout << "latest_version is: " << data[0] << endl;
    int c = 0;
    char* latest_version = new char;
    while(c < length - 1){
        for(int r = 0; r < strlen((*data)[c]); ++r){
            if((int)(*data)[c][r] - (int)(*data)[c + 1][r] < 0){
                latest_version = (*data)[c + 1];
            } 
        }
        c++;
    }
    cout << "latest version is: " << latest_version << endl;
}

int main(int argc, const char* argv[]){
    vector<char*>* data = new vector<char*>;;
    for(int i = 0; i < argc - 1; ++i){
        data->push_back(const_cast<char*>(argv[i + 1]));
    }
    int length = argc - 1;
    get_latest_version(data, length);
    return 0;
}
