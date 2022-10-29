//
// Created by algasami on 2022/10/27.
//
#include <bits/stdc++.h>

using namespace std;

inline int manhattanDistance(int x0, int y0, int x1, int y1) {
    return abs(x0 - x1) + abs(y0 - y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int stationCount, big = 0, small = INT_MAX;
    cin >> stationCount;
    int lx, ly;
    cin >> lx >> ly;
    for (int i = 1; i < stationCount; i++) {
        int rx, ry;
        cin >> rx >> ry;
        int distance = manhattanDistance(lx, ly, rx, ry);
        if (distance > big) big = distance;
        if (distance < small) small = distance;
        lx = rx;
        ly = ry;
    }
    cout << big << " " << small;
    return 0;
}