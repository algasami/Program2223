#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, best = -2, best_time = 0, bad = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t, s;
        scanf("%d %d", &t, &s);
        if (s == -1)
        {
            bad++;
            continue;
        }
        if (best < s)
        {
            best_time = t;
            best = s;
        }
    }
    int score = best - n - bad * 2;
    printf("%d %d", score > 0 ? score : 0, best_time);
    return 0;
}