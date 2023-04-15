#include <bits/stdc++.h>

using namespace std;

int main()
{
    int32_t n, lx, ly, min_dist = INT32_MAX, max_dist = 0;
    scanf("%d", &n);
    scanf("%d %d", &lx, &ly);
    for (int32_t i = 1; i < n; i++) // skip first
    {
        int32_t x, y;
        scanf("%d %d", &x, &y);
        int32_t dist = abs(x - lx) + abs(y - ly);
        min_dist = min(min_dist, dist);
        max_dist = max(max_dist, dist);
        lx = x;
        ly = y;
    }
    printf("%u %u", max_dist, min_dist);

    return 0;
}