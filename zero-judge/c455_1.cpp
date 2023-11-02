#include <bits/stdc++.h>

using namespace std;

// #define DEBUG
// a revision of c455 on zerojudge

#define MAXN 100007

int turn[MAXN * 2], match[MAXN * 2];
vector<int> adjs[MAXN * 2];
// Turn means current query (for Y) no need to initialize it again!
// the indices are combined together
// matching[v] = u)

int cases, current_turn = 0;

bool find_augmented_path(int node) // whether i can find an augmented path or not
{
  #ifdef DEBUG
  printf("find %d\n", node);
  #endif
  turn[node] = current_turn;
  for(int i : adjs[node])
  {
    // i in Y, match[i] in X
    // no need to check for match[i] == node because it means match[node] != -1!!!
    if(match[i] == -1 || (turn[match[i]] != current_turn && find_augmented_path(match[i])) )
    {
      match[i] = node;
      match[node] = i;
      return true;
    }
  }
  return false;
}

int solve() {
  memset(match, -1, sizeof(match));
  memset(turn, -1, sizeof(turn));
  current_turn = 0;
  int p, q, k;
  /**
   * p: Police count of the X Group
   * q: Police count of the Y Group
   * k: Connections between Group X and Y (solve with the **Konig's**
   * algorithm and augmented path maximum bipartite matching?)
   */
  scanf("%d %d %d", &p, &q, &k);

  for( int i = 1; i <= p + q;i++)
  {
    adjs[i].clear();
  }
  for (int i = 0; i < k; i++) {
    int ix, iy;
    scanf("%d %d", &ix, &iy);
    adjs[ix].push_back(iy + p);
    adjs[iy + p].push_back(ix);
  }
  int vertex_cover_count = 0;
  for(int i = 1; i <= p; i++)
  {
    if(match[i] == -1 && find_augmented_path(i)) // if I can find an unique augmented path with i
    {
      vertex_cover_count++;
    }
    current_turn++;
  }

  printf("%d\n", vertex_cover_count);
  return 0;
}

int main() {
  memset(turn, -1, sizeof(turn));
  scanf("%d", &cases);
  for (int i = 0; i < cases; i++) {
    solve();
  }
}