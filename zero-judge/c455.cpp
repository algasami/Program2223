//
// Created by algasami on 2022/10/19.
//
#include <bits/stdc++.h>

using namespace std;

#define maxn 1000001

/*
 * 某警察局將負責巡A城市K個區域R_1,R_2,...,R_K。且將警員分成兩組： X組有p位警衛(x_1,x_2,...,x_p)而Y組有q位員警(y_1,y_2,...,y_p)。
 * 每個員警負責巡邏，且每個員警至少要巡邏一個區域。可構成「警力分配圖」： 有p+q個節點(vertices)和k個邊(edges)，其中p+q個節點對應p+q位警衛。
 * 任務條件：巡邏任一區域的兩位員警而言，要有一位組長。
 * 目標：最少的組長。
 * A police department in charge of patrolling K regions(R_1 ~ R_K) of City A, splitting the policemen into two groups:
 * p individuals in Group X and q of those in Group Y. The above distribution establishes a
 * "policemen dispatching graph", with p+q vertices and k edges, where (X_i,Y_j) corresponds to two policemen.
 * Job Detail: Between two policemen, one has to be a leader.
 * Job Goal: Find the least amount of leaders.
 */

int cases, p, q, k, current;
int V[maxn], F[maxn];
vector<int> adj[maxn];

bool match(int i) {
    for (int j: adj[i]) {
        if (V[j] == 0) {
            V[j] = i;
            return true;
        } else if (F[V[j]] != current) {
            F[V[j]] = current;
            if (match(V[j])) {
                V[j] = i;
                return true;
            }
        }
    }
    return false;
}

int solve() {
    int min_leader = 0;
    memset(V, 0, maxn);
    memset(F, 0, maxn);
    for (int i = 1; i <= p; i++) {
        current = i;
        if (match(i)) min_leader++;
    }
    return min_leader;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> p >> q >> k;
        for (int i = 1; i <= p; i++) {
            adj[i].clear();
        }
        for (int n = 0; n < k; n++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        cout << solve() << "\n";
    }

    return 0;
}