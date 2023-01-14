//
// Created by algasami on 2022/12/15.
//
#include <bits/stdc++.h>

using namespace std;

int x, cg = 0;
set<int> buffer;
string str;
stringstream ss;

/*
 * 5 7 4 3 1 6 9
 * Segment tree
 */

int main() {
    getline(cin, str);
    ss << str;
    while (ss >> x) buffer.insert(x);
    int i = 0, last = 0;
    for (int value: buffer) {
        if (++i == 1) {
            last = value;
            continue;
        }
        if (value - last > cg) cg = value - last;
        last = value;
    }
    cout << cg;
    return 0;
}