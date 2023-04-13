#include <stdio.h>

long long int n, sum = 0;

int main()
{
    scanf("%lld", &n);
    if (n == 0 || n == -1)
    {
        sum = n == 0 ? 1 : 0;
    }
    else if (n > 0)
    {
        sum = n * (n + 1) / 2;
    }
    else
    {
        sum = (1 + n) * (2 - n) / 2;
    }
    printf("%lld", sum);
    return 0;
}