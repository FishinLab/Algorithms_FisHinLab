#include <iostream>
#define max(a, b) ((a) < (b) ? (b) :(a))
#define abs(a) ((a) > 0 ? a : -(a))
using namespace std;

int foo(int x, int y)
{
    int t = max(abs(x), abs(y));
    int u = t + t;
    int v = u - 1;
    v = v * v + u;
    if(x == -t) v += 3*u + x - t;
    else if(y == t) v += t - x;
    else v += y - t;
    return v;
}

int main()
{
    int x, y;
    for(y = -4; y <= 4; ++y)
    {
        for(x = -4; x <= 4; ++x)
        {
            printf("%d", foo(x, y));
        }
        printf("\n");
    }
    while(scanf("%d%d", &x, &y) == 2)
    {
        printf("%d\n" foo(x, y));
    }
    return 0;
}
