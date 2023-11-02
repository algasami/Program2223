#include <bits/stdc++.h>

int n;
char buffer[26];
bool assigned[26] = {false};

void perm(int loc) {
  if (loc == n) {
    for (int i = 0; i < n; i++)
      printf("%c", buffer[i]);
    printf("\n");
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (assigned[i])
      continue;
    assigned[i] = true;
    buffer[loc] = i + 'A';
    perm(loc + 1);
    assigned[i] = false;
  }
}

int main() {
  scanf("%d", &n);
  perm(0);
  return 0;
}