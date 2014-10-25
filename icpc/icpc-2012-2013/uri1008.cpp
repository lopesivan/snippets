#include <cstdio>
using namespace std;

int main() {
  int number, hours;
  double salary;
  scanf("%d%d%lf", &number, &hours, &salary);
  printf("NUMBER = %d\n", number);
  printf("SALARY = U$ %.2lf\n", hours * salary);

  return 0;
}

/*
  25
  100
  5.50

  NUMBER = 25
  SALARY = U$ 550.00
*/
