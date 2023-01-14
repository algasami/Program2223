//
// Created by algasami on 2023/1/14.
//
#include <bits/stdc++.h>

using namespace std;

int dp[501] = {0};

int getVal(int n) {
    if (n == 1) return 1;
    if (dp[n]) return dp[n];
    return getVal(n - 1) + n - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n) {
        cout << getVal(n) << '\n';
    }
    return 0;
}