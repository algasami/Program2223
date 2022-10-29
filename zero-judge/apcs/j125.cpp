//
// Created by algasami on 2022/10/29.
//
#include <bits/stdc++.h>

constexpr int BIG = 1000000;
using namespace std;


int h[300][300], bfs_acc[300][300];
int min_h_offset = BIG, min_path_length = 700;
int n;

inline bool bound(int x, int y) {
    if (!((x >= 0 && y >= 0) && (x < n && y < n))) return false;
    return bfs_acc[y][x] == 0;
}

bool bfs(int minimaOffset) {
    /*
     * Everything inside has to be lower than the maxima offset. (local)
     */
    queue<pair<int, int>> line;
    line.push({0, 0});
    int maxima = -1;
    while (!line.empty()) {
        pair<int, int> const &cur = line.front();
        int x = cur.first;
        int y = cur.second;
        line.pop();

        int tm = abs(h[y - 1][x] - h[y][x]);
        int lm = abs(h[y][x - 1] - h[y][x]);
        int bm = abs(h[y + 1][x] - h[y][x]);
        int rm = abs(h[y][x + 1] - h[y][x]);
        // top
        if (bound(x, y - 1) && tm < minimaOffset) {
            line.push({x, y - 1});
            bfs_acc[y - 1][x] = bfs_acc[y][x] + 1;
            maxima = max(maxima, tm);
        }
        // left
        if (bound(x - 1, y) && lm < minimaOffset) {
            line.push({x - 1, y});
            bfs_acc[y][x - 1] = bfs_acc[y][x] + 1;
            maxima = max(maxima, lm);
        }
        // bottom
        if (bound(x, y + 1) && bm < minimaOffset) {
            line.push({x, y + 1});
            bfs_acc[y + 1][x] = bfs_acc[y][x] + 1;
            maxima = max(maxima, bm);
        }
        // right
        if (bound(x + 1, y) && rm < minimaOffset) {
            line.push({x + 1, y});
            bfs_acc[y][x + 1] = bfs_acc[y][x] + 1;
            maxima = max(maxima, rm);
        }
    }
    if (bfs_acc[n - 1][n - 1] != 0) {
        min_h_offset = maxima;
        min_path_length = bfs_acc[n - 1][n - 1] - 1;
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v;
            cin >> v;
            h[i][j] = v;
        }
    }
    int L = 0, R = BIG;
    while (L < R - 1) {
        memset(bfs_acc, 0, sizeof bfs_acc);
        bfs_acc[0][0] = 1;
        int M = (L + R) / 2;
        if (bfs(M)) R = M;
        else L = M;
    }
    cout << min_h_offset << '\n' << min_path_length;
    return 0;
}