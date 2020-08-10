#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using pii = pair<LL, LL>;

const int maxn = 16;
int n;
int a[maxn];
int ret = INT_MAX;

void dfs(int id, int l, int r, int drop) {///啊啊啊啊啊啊！！！
  if (id == n + 1) {
    if (l == r) {
      ret = min(ret, drop);
    }
    return;
  }
  dfs(id + 1, l + a[id], r, drop);
  dfs(id + 1, l, r + a[id], drop);
  dfs(id + 1, l, r, drop + a[id]);
}


signed main() {
  // freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    ret = INT_MAX;
    dfs(1, 0, 0, 0);
    printf("%d\n", ret);
  }
  system("pause");
  return 0;
}
