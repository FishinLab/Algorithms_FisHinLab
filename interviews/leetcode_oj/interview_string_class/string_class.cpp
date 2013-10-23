#include <iostream>
#include <string.h>

using namespace std;

class inter_string{
    private:
        char* data_;
    public:
        inter_string():data_(new char[1]){
            *data_ = '';
        }

        inter_string(const char* str):data_(new char[strlen(str) + 1]){
            strcpy(data_, str);    
        }
        
        inter_string(const inter_string& str):data_(new char[strlen(str) + 1]){
            strcpy(data_, str.c_str());
        }

        ~inter_string(){
            delete[] data_;
        }

        inter_string& operator=(inter_string str){
            swap(str);
            return *this;
        }

        size_t size() const{
            return strlen(data_);
        }

        const char* c_str() const{
            return data_;
        }
}
