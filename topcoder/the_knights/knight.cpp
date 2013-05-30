#include <iostream>
#include <math.h>

using namespace std;

double get_expected_number(int, pair<int, int>);

int main(int argc, const char* argv[])
{
    int n = atoi(argv[1]); 
    pair<int, int> position;
    position.first = atoi(argv[2]);
    position.second = atoi(argv[3]);
    double result = get_expected_number(n, position);
    cout << result << endl;
    return 0;
}

double get_expected_number(int n, pair<int, int> position)
{
    double exp_result = 0.0; 
    int sum = n * n; 
    int attacked_pos = n + (n - 1);
    int unattacked_pos = sum - attacked_pos;
    
    exp_result = (double)attacked_pos * attacked_pos / sum + (double)unattacked_pos * unattacked_pos / sum; 
    return exp_result;
}
