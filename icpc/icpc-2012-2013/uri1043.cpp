#include<cstdio>
#include<cstdlib>
using namespace std;

int main() {
  double a,b,c;
  scanf("%lf%lf%lf", &a, &b, &c);

  bool triangle = (a+b>c && a+c>b && b+c>a);
  triangle ? printf("Perimetro = %.1lf", a+b+c) : printf("Area = %.1lf",(a+b)/2.0*c);


  return 0;
}

/*
6.0 4.0 2.0
*/
