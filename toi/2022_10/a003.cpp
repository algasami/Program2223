//
// Created by algasami on 2022/11/2.
//
#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> pool;

int maximum = 0;

void dfs(const vector<int> &now) {
    for (int i = 0; i < n; i++) {
        if (find(now.begin(), now.end(), i) != now.end())continue;
        const auto &p = pool[now.back()];
        if (p.first > pool[i].first && p.second > pool[i].second) {
            vector<int> copy = now;
            copy.push_back(i);
            dfs(copy);
        }
    }
    maximum = max((int) now.size(), maximum);
}

int main() {
    cin >> n;
    pool = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++) {
        int l, w;
        cin >> l >> w;
        pool[i].first = l;
        pool[i].second = w;
    }
    for (int i = 0; i < n; i++)
        dfs({i});
    cout << maximum;
    return 0;
}