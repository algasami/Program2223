#include <bits/stdc++.h>

using namespace std;

#define DEBUG

#define MAX_N 100007

int turn[MAX_N], matching[MAX_N]; // y -> x
vector<int> adjs[MAX_N];          // x -> y

int current_turn = 0;

/**
 * this function finds if we can traverse through an augmented path or not
 * simultaneously, it swaps the matching
 * for example: A --- B ----- C ----- D where (A, C) = U and (B, D) = V
 * find_augmented_path(A)
 *      -> matching[B] = A
 * A === B --- C --- D : okay
 * find_augmented_path(C)
 *      -> find_augmented_path(A): X (B has been traversed since we have sought
 * B)
 *      -> matching[D] = C
 * A === B --- C === D
 */
bool find_augmented_path(int x) {
  for (auto iter = adjs[x].begin(); iter != adjs[x].end(); iter++) {
    int y = *iter;
    if (turn[y] != current_turn) {
      turn[y] = current_turn;
      if (matching[y] == -1 ||
          (matching[y] != x && find_augmented_path(matching[y]))) {
        matching[y] = x;
        return true;
      }
    }
  }
  return false;
}

void solve() {
  memset(matching, -1, sizeof(matching));
  memset(turn, -1, sizeof(turn));
  current_turn = 0;
  int p, q, k;
  scanf("%d %d %d", &p, &q, &k);
  for (int i = 1; i <= p; i++) {
    adjs[i].clear();
  }

  for (int i = 0; i < k; i++) {
    int ix, iy;
    scanf("%d %d", &ix, &iy);
    adjs[ix].push_back(iy);
  }

  int vertex_cover_count = 0;
  for (int i = 1; i <= p; i++) {
    ++current_turn;
    // we don't need to check if U[i] is matched or not
    // since it is the latest one (doesn't get matched by the algorithm)
    // I won't leave a proof here... proof with intuition (voila!)
    if (find_augmented_path(i)) {
      vertex_cover_count++;
      // in Konig's theorem, it states that maximum vertex cover count equals
      // maximum matching count. here, maximum matching count is incremented
      // because find_augmented_path increases cardinality by one via augmented
      // path inversion (Tenet, baby!)
    }
  }
  printf("%d\n", vertex_cover_count);
}

int main() {
  int cases;
  scanf("%d", &cases);
  while (cases--) {
    solve();
  }
}