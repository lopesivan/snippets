#include <stdio.h>
#include <math.h>

int main() {
  int TC, i;
  double d, u, v;
  double fast, perp, tfast, tperp;

  scanf("%d", &TC);

  for (i = 1; i <= TC; i++) {
    
    scanf("%lf%lf%lf", &d, &v, &u);

    /* Faster: u */
    /* Perpendicular: se u <= v, can't determine.
     * but if u > v, sqrt(u^2-v^2) */

    fast = u;
	tfast = d / fast;
    perp = u*u - v*v;

    printf("Case %d: ", i);

    if (perp <= 0)
      puts("can't determine");
    else {
      perp = sqrt(perp);
	  tperp = d / perp;
      printf("%.3lf\n", tperp - tfast );
    }


  }

  return 0;
}
