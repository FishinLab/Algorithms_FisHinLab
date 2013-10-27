#include <iostream>
#include <math.h>

using namespace std;
int get_bigger(int a, int b)
{
    return ((a + b) + abs(a - b) )/2;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int res = get_bigger(a, b);
    printf("%d", res);

    return 0;
}
