#include <iostream>

using namespace std;

int main()
{
    char* ss1 = "1234567890";           
    char ss2[] = "1234567890";          
    char ss3[100] = "1234567890";       

    int ss4[100];                       

    char q1[] = "abc";                  
    char q2[] = "a\n";                  
    char* q3 = "a\n";                   

    char *str1 = (char*)malloc(100);    
    void *str2 = (void*)malloc(100);    

    cout << "char* ss1 = \"1234567890\" : " << sizeof(ss1) << endl; //11
    cout << "char ss2[] = \"1234567890\" : " << sizeof(ss2) << endl; //11
    cout << "char ss3[100] = \"1234567890\" : " << sizeof(ss1) << endl; //100

    cout << "int ss4[100] : " << sizeof(ss4) << endl; //100

    cout << "char q1 = \"abc\" : " << sizeof(q1) << endl; //3
    cout << "char q2 = \"a\\n\" : " << sizeof(q2) << endl; //3
    cout << "char* q3 = \"a\\n\" : " << sizeof(q3) << endl; //4

    cout << "char* str1 = (char*)malloc(100) : " << sizeof(str1) << endl; //100
    cout << "void* str2 = (void*)malloc(100): " << sizeof(str1) << endl; //100

    return 0;
}
