#include <bits/stdc++.h>

using namespace std;

int a[1005], b[1005], ra[1005];
int dp[1005][1005], r_dp[1005][1005], ans = -1000000;
// dp[i][j]
// a ending in i, b ending in j, max dot
// dp[0][0] should be max(0, a[0]*b[0]); dp[i][j] = 0 means relinquishing
// the value of previous dot product. (aka starting a new array)

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        ra[n - i - 1] = a[i];
    }
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = a[i] * b[0];
        r_dp[i][0] = ra[i] * b[0];
        ans = max(max(dp[i][0], r_dp[i][0]), ans);
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = a[0] * b[j];
        r_dp[0][j] = ra[0] * b[j];
        ans = max(max(dp[0][j], r_dp[0][j]), ans);
    }

    // dp[i][j] = max(0, dp[i-1][j-1]) + a[i]*b[j]
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(0, dp[i - 1][j - 1]) + a[i] * b[j];
            r_dp[i][j] = max(0, r_dp[i - 1][j - 1]) + ra[i] * b[j];
            ans = max(max(dp[i][j], r_dp[i][j]), ans);
        }

    printf("%d", ans);
    return 0;
}