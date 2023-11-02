#include <bits/stdc++.h>
using namespace std;

int n, m, s, h1[256], h2[256];
string in;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin.get();
  for (int i = 0; i < n; i++) {
    memset(h1, 0, sizeof(h1));
    memset(h2, 0, sizeof(h2));
    // solve
    getline(cin, in);
    for (int i = 0; i < in.size(); ++i) {
      m = max(m, (int)in[i]);
      ++h1[in[i]];
    }
    getline(cin, in);
    for (int i = 0; i < in.size(); ++i) {
      m = max(m, (int)in[i]);
      ++h2[in[i]];
    }
    bool f = true;
    for (int i = 0; i < m; ++i) {
      if (h1[i] != h2[i]) {
        cout << "impossible\n";
        f = false;
        break;
      }
    }
    if (f == true) {
      cout << "possible\n";
    }
  }
  return 0;
}