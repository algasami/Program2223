//
// Created by algasami on 2022/10/18.
//
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

int n;
bool data[101] = {0};
uint big = 0, small = -1;

/*
 * Input: n, x_1, x_2, ..., x_n
 * Output: min(x) max(x) yes or no (consistency)
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        uint x; cin >> x; data[x] = 1;
        big = max(big, x); small = min(small, x);
    }
    uint in_between = 0;
    for(uint i = small; i <= big; i++)
    {
        in_between += data[i];
    }
    cout << small << " " << big << " ";
    if(in_between == big - small + 1)
    {
        cout << "yes";
    }else
    {
        cout << "no";
    }
    return 0;
}
