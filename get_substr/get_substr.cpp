#include <iostream>

using namespace std;
int sum = 0;
char str[] = "hart";
int length;
char* out;

void do_combine(char in[], char out[], int length, in rec, int start)
{
    int i;
    for(i = start; i < length;++i){
        out[rec] = in[i];
        out[rec + 1] = 0;
        printf("%s\n", out);
        if(i < length - 1) do_combine(in, out, length, rec + 1, i + 1);
    }
}

int main()
{
    length = strlen(str);
    out = (char*)malloc(length + 1);
    do_combine(str, out, length, 0, 0);
    return 0;
}
