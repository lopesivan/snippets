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

int main(int argc, char* argv[]) {
  ll target = 600851475143;
  int largest = -1;
  
  for (int p = 3; p * p <= target; p += 2) {
    bool once = false;
    while (!(target % p)) {
      target /= p;
      once = true;
    }
    if (once)
      largest = p;
  }
  largest = max(target, ll(largest));
  
  printf("%d\n", largest);

  return 0;
}
