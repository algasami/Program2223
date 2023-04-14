#include <bits/stdc++.h>

using namespace std;
int k, q, r;
char str[21];
char mat[21][21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k >> q >> r >> str;
    for (int i = 0; i < q; i++)
    {
        char repl_str[21];
        for (int j = 0; j < k; j++)
        {
            int to;
            cin >> to;
            repl_str[to - 1] = str[j];
        }
        strcpy(str, repl_str);
        for (int j = 0; j < r; j++)
        {
            mat[j][i] = str[j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}