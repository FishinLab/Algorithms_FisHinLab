#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char* argv[])
{
    pair<int>* p_src_data = new pair<int>;
    p_src_data->first = argv[1];
    p_src_data->second = argv[2];
    return 0;
}
