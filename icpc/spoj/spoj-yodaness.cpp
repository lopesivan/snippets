/*
  Problem Judge: SPOJ
  http://www.spoj.com/problems/YODANESS/
  Solved with a single BIT.
  It could also be solved using a merge sort counting.
*/

#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

int t[31000];
int n;
void update(int x) {
  for (; x <= n; x+=x&-x) ++t[x];
}
int query(int x) {
  int ans;
  for (ans = 0; x > 0; x-=x&-x) ans+=t[x];
  return ans;
}

int main() {
  int TC;
  map<string,int> m;
  char tmp[100];
  scanf("%d%*c", &TC);
  t[0] = 0;

  while (TC--)
  {
    scanf("%d", &n);
    int ans = 0;
    m.clear();
    for (int i = n; i > 0; --i) {
      scanf("%s", tmp);
      m[tmp]=i;
      t[i] = 0;
    }
    for (int i = 1; i<= n; ++i) {
      scanf("%s", tmp);
      int x = m[tmp];
      update(x);
      ans += query(x-1);
    }

    printf("%d\n", ans);
  }

  return 0;
}
