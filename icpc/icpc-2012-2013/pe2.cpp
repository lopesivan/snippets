#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int factual = 1;
  int fnext = 1;
  int i = 0;
  long long int sum = 0;
  
  while (fnext <= 4e6) {
    swap(factual, fnext);
    fnext += factual;
    if (!(i%3))
      sum += fnext;
    ++i;
  }

  printf("%lld\n", sum);

  return 0;
}
