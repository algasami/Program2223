//
// Created by algasami on 2022/10/27.
//
#include <bits/stdc++.h>

using namespace std;

int height, width, n, occupyBlock = 0, cargoCount = 0;
int w[40];

void A(int y) {
    int maxWidth = 0;
    for (int i = y; i <= y + 3; i++)maxWidth = max(maxWidth, w[i]);
    if (maxWidth + 1 <= width) {
        occupyBlock += 4;
        cargoCount++;
        for (int i = y; i <= y + 3; i++)w[i] = maxWidth + 1;
    }
}

void B(int y) {
    if (w[y] + 3 <= width) {
        occupyBlock += 3;
        cargoCount++;
        w[y] += 3;
    }
}

void C(int y) {
    int maxWidth = max(w[y], w[y + 1]);
    if (maxWidth + 2 <= width) {
        occupyBlock += 4;
        cargoCount++;
        w[y] = w[y + 1] = maxWidth + 2;
    }
}

void D(int y) {
    //##_O_
    //#OOO_
    if (w[y + 1] + 3 <= width && w[y] + 1 <= width) {
        occupyBlock += 4;
        cargoCount++;
        if (w[y] + 1 >= w[y + 1] + 3) {
            w[y]++;
            w[y + 1] = w[y];
        } else {
            w[y] = w[y + 1] = w[y + 1] + 3;
        }
    }
}

void E(int y) {

    if (w[y] + 1 <= width && w[y + 1] + 2 <= width && w[y + 2] + 2 <= width) {
        occupyBlock += 5;
        cargoCount++;
        if (w[y] + 1 >= w[y + 1] + 2 && w[y] + 1 >= w[y + 2] + 2) {
            // ##O
            // #OO
            // #OO
            w[y + 1] = w[y + 2] = w[y] = w[y] + 1;
        } else if (w[y + 2] + 2 >= w[y] + 1 || w[y + 1] + 2 >= w[y] + 1) {
            // #  O
            // # OO
            // ##OO
            // or
            // #  O
            // ##OO
            // # OO
            int wd = max(w[y + 1] + 2, w[y + 2] + 2);
            w[y] = w[y + 1] = w[y + 2] = wd;
        }
    }
}

int main() {
    cin >> height >> width >> n;

    for (int i = 0; i < n; i++) {
        char type;
        int y;
        cin >> type >> y;
        switch (type) {
            case 'A':
                A(y);
                break;
            case 'B':
                B(y);
                break;
            case 'C':
                C(y);
                break;
            case 'D':
                D(y);
                break;
            case 'E':
                E(y);
                break;
            default:
                break;
        }
    }
    cout << height * width - occupyBlock << " " << n - cargoCount;
    return 0;
}