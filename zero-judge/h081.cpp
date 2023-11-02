#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, D, hold = -1, prev = -1, sum = 0;
    scanf("%d %d", &n, &D);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (hold != -1 && x >= hold + D)
        {
            sum += x;
            prev = x;
            hold = -1;
        }
        else if (hold == -1 && (prev == -1 || x <= prev - D))
        {
            sum -= x;
            hold = x;
        }
    }
    printf("%d", max(sum, 0));
    return 0;
}