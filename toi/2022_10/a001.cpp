//
// Created by algasami on 2022/11/2.
//

#include <bits/stdc++.h>

using namespace std;

int center_count, old_vertices;
set<int> bandwidth_set;
vector<map<int, int>> graph;


int main() {
    cin >> center_count >> old_vertices;
    graph = vector<map<int, int>>(center_count);
    for (int i = 0; i < old_vertices; i++) {
        int a, b, bandwidth;
        cin >> a >> b >> bandwidth;
        a--;
        b--;
        graph[a][b] = bandwidth;
        graph[b][a] = bandwidth;
        bandwidth_set.insert(bandwidth);
    }
    int i = 0;
    for (int c: bandwidth_set) {
        if (i++ == 1) {
            cout << c;
            return 0;
        }
    }
    return 0;
}