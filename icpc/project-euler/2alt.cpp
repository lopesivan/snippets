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
  int prev = 0;
  int curr = 2;
  int tmp;
  // fn = 4fn-3 + fn-6
  int target = 4e6;
  int sum = prev + curr;

  while (true) {
    tmp = prev;
    prev = curr;
    curr = 4 * prev + tmp;
    if (curr > target)
      break;
    sum += curr;
  }

  printf("%d\n", sum);
  
  return 0;
}
