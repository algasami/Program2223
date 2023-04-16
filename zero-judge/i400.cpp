#include <bits/stdc++.h>

using namespace std;

int m, n;
char encrypts[105][105], cipher[105];

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
        scanf("%105s", encrypts[i]);

    scanf("%105s", cipher);
    return 0;
}