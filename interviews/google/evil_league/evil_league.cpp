#include <iostream>
#include <vector>
#include <map>

using namespace std;

void check_loop(vector<pair<char*, char*> > vertex){
    char* now = vertex[0].first; 
    map<char*, int> hash_store;
    for(vector<pair<char*, char*> >::iterator iv = vertex.begin(); iv != vertex.end(); ++iv){
        hash_store[(*iv).first] = 0;
        hash_store[(*iv).second] = 0;
    }
    hash_store[now] = 1;
    vector<pair<char*, char*> >::iterator iv = vertex.begin();
    while(iv != vertex.end()){
        if(hash_store[now] != 0){
            for(map<char*, int>::iterator im = hash_store.begin(); im != hash_store.end(); ++im){
                if((*im).second == 1){ 
                    printf("this graph could be seperated\n"); 
                    return;
                }
            }
            printf("this graph could not be seperated\n");
            return;
        } 
        hash_store[now] = 1;
        now = (*iv).second; 
        iv++;
    }
    printf("this graph could be seperated\n");
    delete now;
}

int main(){
    FILE* p_data = fopen("./test.data", "r");
    char* p_line = new char[1024];
    fgets(p_line, 1024, p_data);
    int m = atoi(p_line);
    for(int i = 0; i < m; ++i){
        fgets(p_line, 1024, p_data);
        int n = atoi(p_line);
        int cn = 0;
        vector<pair<char*, char*> > vertex;
        while(cn < n){
            fgets(p_line, 1024, p_data);
            int x;
            for(x = 0; p_line[x] != ' ' && p_line[x] != '\0'; ++x);
            char* tmp = new char[1024];
            strncpy(tmp, p_line, x);
            pair<char*, char*> tmp_pair;
            tmp_pair.first = tmp;
            strncpy(tmp, p_line + x + 1, strlen(p_line) - x);
            tmp_pair.second = tmp;
            vertex.push_back(tmp_pair);
            cn++;
        }
        check_loop(vertex);
    }
    fclose(p_data);
    return 0;
}
