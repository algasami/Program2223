//
// Created by algasami on 2023/1/14.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        for (int i = 1; i < n; i++) {
            if (i % 7 != 0) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}