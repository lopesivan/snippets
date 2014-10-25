#include <cstdio>
#include <cstdlib>
using namespace std;
inline double min(double a, double b) {
  return a < b ? a : b;
}

int main() {

  int a, b, TC = 0;

  while (scanf("%d%d", &a, &b), a || b) {
    printf("Case %d: ", ++TC);

    double c = min(1.0, double(b)/a );
    double d = min(1.0, double(b-1)/(a-1) ) ;

    // printf("%lf\n", double(b)/a );
    // printf("%lf %lf\n", c, d);

    if (a == 1)
      printf(":-\\\n");
    else if (c == d)
      printf(":-|\n");
    else if ( c >  d )
      printf(":-(\n");
    else 
      printf(":-)\n");
  }

  return 0;

}
