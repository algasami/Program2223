#include <bits/stdc++.h>

using namespace std;

int max_val[10] = {0};
set<int, greater<int>> s;

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int x;
        scanf("%d", &x);
        s.insert(x);
        max_val[x]++;
    }
    int maxv = 0;
    for (int i = 0; i < 9; i++)
    {
        maxv = max(max_val[i], maxv);
    }
    printf("%d ", maxv);
    for (int x : s)
    {
        printf("%d ", x);
    }
    return 0;
}