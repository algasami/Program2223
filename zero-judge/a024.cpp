//
// Created by algasami on 2023/1/14.
//
#include <bits/stdc++.h>

using namespace std;

int greatest(int x, int y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << greatest(x, y);
    return 0;
}