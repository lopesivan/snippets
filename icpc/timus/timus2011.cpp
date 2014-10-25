#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int f(int n) {
  if (!n)
    return 1;
  else
    return n * f(n - 1);
}

int main() {
  int n;
  int v[150];
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    scanf("%d", &v[i]);

  if (n >= 6) {
    bool diff = false;
    for (int i = 0; i < n - 1; ++i) {
      if (v[i] != v[i+1]) {
	diff = true;
	break;
      }
    }
    diff ? puts("Yes") : puts("No");
  }
  else {
    sort(v, v + n);
    int total = f(n);
    int curr = 1;
    for (int i = 0; i < n - 1; ++i) {
      if (v[i] != v[i+1]) {
	total /= f(curr);
	curr = 1;
      }
      else
	++curr;
    }
    total /= f(curr);
    total >= 6 ? puts("Yes") : puts("No");
  }
  
  return 0;
}
