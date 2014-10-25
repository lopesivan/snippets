#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
const int MAX = 5010;

int main() {
  int s, p;
  int a, b, TC = 0;
  vector< pair<int,int> > v(MAX, pair<int,int> ());

  while ( scanf("%d%d", &p, &s), p || s ) {
    printf("Teste %d\n", ++TC);

    for (int i = 0; i < s; ++i ) {
      scanf("%d%d", &a, &b);
      v[i] = pair<int,int>(a,b);
    }

    int c, d;
    sort(v.begin(), v.begin() + s);

    a = v[0].first;
    b = v[0].second;

    for (int i = 0; i < s - 1; ++i) {
      c = v[i+1].first;
      d = v[i+1].second;

      if (c > b) {
	printf("%d %d\n", a, b);
	a = c;
	b = d;
      }
      else if (b <= d) {
	b = d;
      }
    }
    printf("%d %d\n\n", a, b);
  }

  return 0;
}
