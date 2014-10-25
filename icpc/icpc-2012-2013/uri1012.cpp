#include <cstdio>
using namespace std;
#define PI 3.14159

int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);

  printf("TRIANGULO: %.3lf\n", (a * c) / 2);
  printf("CIRCULO: %.3lf\n", c * c * PI);
  printf("TRAPEZIO: %.3lf\n", c * (a + b) / 2);
  printf("QUADRADO: %.3lf\n", b * b);
  printf("RETANGULO: %.3lf\n", a * b);

  return 0;
}

/*
  3.0 4.0 2.0

  TRIANGULO: 3.000
  CIRCULO: 12.566
  TRAPEZIO: 7.000
  QUADRADO: 16.000
  RETANGULO: 12.000
*/
