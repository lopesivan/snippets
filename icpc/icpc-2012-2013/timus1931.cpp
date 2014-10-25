#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int next;
  int disad;
  int pos, lastpos;
  int times,lasttimes;
  scanf("%d%d", &n, &next);

  lasttimes=times=0;
  lastpos=pos=1;
  disad=next;

  for (int i = 1; i < n; ++i) {
    scanf("%d", &next);

    ++times;

    if (disad > next) {
      if (times > lasttimes) {
	lasttimes = times;
	lastpos = pos;
      }
      pos=i+1;
      times=1;
      disad=next;

    }
  }

  if (times > lasttimes) {
    lasttimes = times;
    lastpos = pos;
  }

  printf("%d\n",lastpos);

  return 0;
}
