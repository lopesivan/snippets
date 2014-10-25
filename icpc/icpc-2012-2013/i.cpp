#include <cstdio>
#include <cmath>
using namespace std;

long long int mod(const long long int a) {
  return a > 0 ? a : -a;
}

int signal(const double a) {
  return a > 0 ? 1 : -1;
}

int signal(const long long int a) {
  return a > 0 ? 1 : -1;
}


int main() {
  int n;
  int a1, c1, a2, c2;
  scanf("%d", &n);

  while(n--) {
    scanf("%d%d%d%d\n", &a1, &c1, &a2, &c2);
    double ans;
    if (a1 != a2)
      ans = double(c2 - c1) / double(a2 - a1);
    else
      ans = double(c2);
    long long int first, last;
    first = int(ans);
    last = mod(int((ans - int(ans)) * 100));
    // last = int(last * 100);
    // last = int(floor(mod(ans) * 100)) % 100;
    printf("%lld,%02lld\n", first, last);

  }
  

  return 0;
}
