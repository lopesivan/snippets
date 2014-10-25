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
  int lim = 999;
  int sum = 0;

  int mul3 = lim / 3;
  int mul5 = lim / 5;
  int mul15 = lim / 15;

  // sum3
  sum += (3 + 999) * mul3 / 2;
  sum += (5 + 995) * mul5 / 2;
  sum -= (15 + 990) * mul15 / 2;
  
  printf("%d\n", sum);
  
  return 0;
}
