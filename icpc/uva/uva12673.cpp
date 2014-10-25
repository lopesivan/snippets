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
// struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double EPS = 1e-7;

int main(int argc, char* argv[]) {
  int n, g;
  vector<int> v;
  int a, b;

  while ( scanf("%d", &n) == 1) {
    scanf("%d", &g);
    int points = 0;
    v.clear();
    for (int i = 0; i < n;  ++i) {
      scanf("%d%d", &a, &b);
      int diff = a - b;
      if (diff > 0) {
	points += 3;
      }
      else if (!diff) {
	points++;
	if (g > 0) {
	  --g;
	  points += 2;
	}
      }
      else {
	v.push_back(abs(diff));
      }
    }
    sort(v.begin(), v.end());

    int i = 0;
    int tam = v.size();

    while (g > 0 && i < tam) {
      if (g > v[i]) {
	points += 3;
	g -= (v[i] + 1);
      }
      else if (g == v[i]) {
	points++;
	break;
      }
      else {
	break;
      }
      ++i;
    }

    printf("%d\n", points);
  }
  return 0;
}
