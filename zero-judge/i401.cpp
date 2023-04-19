#include <bits/stdc++.h>

using namespace std;
constexpr int N_MAX = 30000;

vector<pair<int, int>> fx[N_MAX + 8], fy[N_MAX * 2 + 8];
// fx: index with x, expect sorted y,t
// fy: index with y, expect sorted x,t

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        y += N_MAX;
        fx[x].emplace_back(y, t);
        fy[y].emplace_back(x, t);
    }
    for (int i = 0; i <= N_MAX; i++)
        sort(fx[i].begin(), fx[i].end());
    for (int i = 0; i <= N_MAX * 2; i++)
        sort(fy[i].begin(), fy[i].end());

    int cx = 0, cy = N_MAX, d = 1, b = 0;
    // d: right, up, left, down
    // t = 0 : /
    // t = 1 : \

    while (1)
    {
        if (d == 1)
        {
            const auto hit =
                upper_bound(fy[cy].begin(), fy[cy].end(), make_pair(cx, 1));
            if (hit == fy[cy].end())
                break;
            cx = hit->first;
            d = hit->second == 0 ? 2 : 4;
        }
        else if (d == 2)
        {
            const auto hit =
                upper_bound(fx[cx].begin(), fx[cx].end(), make_pair(cy, 1));
            if (hit == fx[cx].end())
                break;
            cy = hit->first;
            d = hit->second == 0 ? 1 : 3;
        }
        else if (d == 3)
        {
            auto hit =
                lower_bound(fy[cy].begin(), fy[cy].end(), make_pair(cx, 0));
            if (hit == fy[cy].begin())
                break;
            hit--;
            cx = hit->first;
            d = hit->second == 0 ? 4 : 2;
        }
        else if (d == 4)
        {
            auto hit =
                lower_bound(fx[cx].begin(), fx[cx].end(), make_pair(cy, 0));
            if (hit == fx[cx].begin())
                break;
            hit--;
            cy = hit->first;
            d = hit->second == 0 ? 3 : 1;
        }
        b++;
    }
    printf("%d\n", b);
    return 0;
}