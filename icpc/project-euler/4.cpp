#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double EPS = 1e-7;

bool ispal(int x) {
  char tmp[50];
  sprintf(tmp, "%d", x);
  int tam = strlen(tmp);
  for (int i = 0; i < tam / 2; ++i) {
    if (tmp[i] != tmp[tam - 1 - i])
      return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  int n1 = 100;
  int n2 = 100;
  int ans = -1;

  for ( ; n1 < 1000; ++n1) {
    for (n2 = 100 ; n2 <= n1; ++n2) {
      int prod = n1 * n2;
      if (ispal(prod))
        ans = max(ans, prod);
    }
  }

  printf("%d\n", ans);

  return 0;
}
