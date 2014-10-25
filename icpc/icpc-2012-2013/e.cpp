#include <cstdio>

int main() {
  int TC;
  scanf("%d\n", &TC);

  while(TC--) {
    int t1c, t1v, t2c, t2v;
    scanf("%d x %d\n%d x %d\n", &t1c, &t2v, &t2c, &t1v);

    int s1 = 0;
    int s2 = 0;
    
    // partida 1
    if (t1c > t2v)
      s1 += 3;
    else if (t1c < t2v)
      s2 += 3;

    // partida 2
    if (t2c > t1v)
      s2 += 3;
    else if (t2c < t1v)
      s1 += 3;

    if (s1 > s2) {
      puts("Time 1");
    }
    else if (s1 < s2) {
      puts("Time 2");
    }
    else if (t1v > t2v) {
      puts("Time 1");
    }
    else if (t1v < t2v) {
      puts("Time 2");
    }
    else {
      puts("Penaltis");
    }

    continue;      
  }  

  return 0;
}
