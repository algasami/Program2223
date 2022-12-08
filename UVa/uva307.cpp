//
// Created by algasami on 2022/11/9.
//

// UVa 307
#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1000000;
int n, sticks[MAX_N], len;
bool used[MAX_N];

/*
 * Backtracing is crucial
 */
bool dfs(int cut_index, int current_len, int stick_sum) {
    if (cut_index >= n) return false;
    cout << "dfs(" << cut_index << "," << current_len << "," << stick_sum << ")";
    if (current_len == sticks[cut_index]) { // cut the og stick entirely out...
        stick_sum -= sticks[cut_index];
        current_len = len;
        cout << "\\n->(" << cut_index << "," << current_len << "," << stick_sum << ")\n";
        if (stick_sum == 0) return true;
        used[cut_index] = true;
        int first_unused;
        for (first_unused = 0; used[first_unused]; ++first_unused);
        if (dfs(first_unused, current_len, stick_sum)) return true;
        used[cut_index] = false;
    } else if (current_len > sticks[cut_index]) {
        // Cut partial
        stick_sum -= sticks[cut_index];
        current_len -= sticks[cut_index];
        cout << "\\n->(" << cut_index << "," << current_len << "," << stick_sum << ")\n";
        used[cut_index] = true;
        for (int i = cut_index; i < n; i++) {
            if (i > 0 && sticks[i - 1] == sticks[i] && !used[i - 1]) continue;
            if (!used[i] && current_len >= sticks[i]) {
                if (dfs(i, current_len, stick_sum)) return true;
            }
        }
        // Revert used state -- backtracking
        used[cut_index] = false;
    }
    return false;
}

int sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> n && n != 0) {
        sum = 0;
        memset(used, false, n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            sticks[i] = x;
        }
        // all possible len: sum % len == 0 && there were at least one stick
        sort(sticks, sticks + n, [](int a, int b) { return a > b; });
        // [sum/2] >= len >= a_0
        for (len = sticks[0]; len <= sum; len++) {
            if (sum % len != 0) continue;
            // cout << "new!\n";
            if (dfs(0, len, sum)) {
                cout << len << '\n';
                break;
            }
            used[0] = false;
        }
    }
    return 0;
}