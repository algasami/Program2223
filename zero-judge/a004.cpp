//
// Created by algasami on 2023/1/14.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0))
            cout << "閏年" << endl;
        else
            cout << "平年" << endl;
    }
    return 0;
}