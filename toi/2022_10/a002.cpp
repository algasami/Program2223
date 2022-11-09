//
// Created by algasami on 2022/11/2.
//
#include <bits/stdc++.h>

using namespace std;

int roulette_count, player_count, card_count;
vector<int> roulette;
map<int, int> inverse_roulette;
vector<queue<int>> player;

vector<int> ans;

void sim() {
//    int cursor = 0, round = 0;
    while (true) {
//        round++;
        bool all_pass = true;
        for (int min: ans) {
            if (min == 0) {
                all_pass = false;
                break;
            }
        }
        if (all_pass) return;
//        int tmp = (cursor + 1) % roulette_count;
//        cursor = tmp == 0 ? roulette_count : tmp;
        for (int i = 0; i < player_count; i++) {
            int round = 0, cursor = 0;
            int tmp = (cursor + 1) % roulette_count;
            cursor = tmp == 0 ? roulette_count : tmp;
            if (ans[i] != 0) continue;
            int f = player[i].front();
            if (f == roulette[cursor - 1]) player[i].pop();
            if (player[i].empty()) ans[i] = round;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> roulette_count >> player_count >> card_count;
    roulette = vector<int>(roulette_count);
    player = vector<queue<int>>(player_count);
    ans = vector<int>(player_count);
    for (int i = 0; i < roulette_count; i++) {
        int x;
        cin >> x;
        roulette[i] = x;
        inverse_roulette[x] = i;
    }
    for (int i = 0; i < player_count; i++)
        for (int j = 0; j < card_count; j++) {
            int x;
            cin >> x;
            if (find(roulette.begin(), roulette.end(), x) == roulette.end()) {
                ans[i] = -1;
            }
            player[i].push(x);
        }
    sim();
    for (int a: ans) {
        cout << a << '\n';
    }
    return 0;
}
/*
 *
8 3 5
2 3 1 3 2 0 4 0
2 1 3 4 0
3 1 1 0 3
1 3 0 5 4
 */