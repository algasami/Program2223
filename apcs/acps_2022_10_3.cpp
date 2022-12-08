//
// Created by algasami on 2022/10/27.
//
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

/*
 * Even = two leaves
 * Odd = three leaves
 */

ll sum = 0;

void dfs(int i) {
    if (i == 0) return;
    for (int c = 0; c < (i % 2 == 0 ? 2 : 3); c++) {
        int next;
        cin >> next;
        if (next == 0) continue;
        sum += abs(i - next);
        dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int root;
    cin >> root;
    dfs(root);
    cout << sum;
    return 0;
}