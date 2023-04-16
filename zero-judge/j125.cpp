#include <bits/stdc++.h>

using namespace std;

int n;
int height[305][305];

// predefine directions (quality of life)
int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

// debug purpose
void dbg(int ptr[][305])
{
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
            printf("%d\t", ptr[i][j]);
        printf("\n");
    }
}

// traditional bfs
int traverse(int max_delta)
{
    int map[305][305];
    memset(map, -1, sizeof map);

    queue<pair<int, int>> q;
    q.push({1, 1});
    map[1][1] = 0;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int di = 0; di < 4; di++)
        {
            int ix = x + directions[di][0];
            int iy = y + directions[di][1];
            int dist = abs(height[iy][ix] - height[y][x]);
            // this automatically eliminates boundary issue
            if (dist > max_delta || map[iy][ix] != -1)
                continue;

            map[iy][ix] = map[y][x] + 1;
            q.push({ix, iy});
        }
    }

    return map[n][n];
}

int main()
{
    memset(height, 0, sizeof height);
    scanf("%d", &n);
    // notice that i start from 1 and ends with i == n
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &height[i][j]);

    // set up soft boundaries
    for (int i = 0; i <= n + 1; i++)
    {
        height[i][0] = INT_MAX;
        height[i][n + 1] = INT_MAX;
        height[0][i] = INT_MAX;
        height[n + 1][i] = INT_MAX;
    }

    // essentially what i'm doing here is finding the minimum range delta
    // threshold for our traversal algorithm.
    int l = -1, r = 1000000, mid, len;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        int tmp = traverse(mid);
        if (tmp == -1) // too strict, increase threshold
            l = mid;
        else
        {
            len = tmp;
            r = mid;
        }
    }
    printf("%d\n%d", r, len);

    return 0;
}