//
// Created by algasami on 2023/1/14.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.get();
    for (int i = 0; i < t; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int trash = 0, a1, a2, a3;
        ss >> trash >> a1 >> a2 >> a3;
        int pos_offset = a2 - a1;
        cout << s << ' ';
        if (pos_offset == a3 - a2) {
            cout << a3 + pos_offset << endl;
            continue;
        }
        int pos_power = a2 / a1;
        cout << a3 * pos_power << endl;
    }
    return 0;
}