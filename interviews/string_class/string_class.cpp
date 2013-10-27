#include <iostream>

using namespace std;

class my_string{
    public:
        my_string(const char* str = NULL);
        my_string(const my_string &str);
        ~my_string(void);
        my_string & operator = (const my_string &str);
    private:
        char* my_char;
};

my_string::~my_string(void){
    delete[] str;
}

my_string::my_string(const char* str = NULL){
    if(str == NULL){
        my_char = new char[1];
        *my_char = '\0';
    }
    else{
        int length = strlen(str);
        my_char = new char[length + 1];
        strcpy(my_char, str);
    }
}

my_string::my_string(const my_string &str){
    int length = strlen(str.my_char);
    my_char = new char[length + 1];
    strcpy(my_char, str.my_char);
}

my_string::operator = (const my_string &str){
    if(this == &str){
        return *this; 
    }
    delete[] my_char;
    int length = strlen(str.my_char + 1);
    my_char = new char[length];
    strcpy(my_char, str.my_char);
    return *this;
}

int mainR()
{
    const char* test_data = "hello world!";
    my_string str_1(test_data);
    my_string str_2 = str_1;
    my_string str_3;

    //cout << "test string one : " << str_1 << "test string two : " << str_2 << "test string three : " << str_3 << endl;
    return 0;
}
