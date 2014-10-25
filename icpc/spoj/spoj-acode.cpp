#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

char input[5100];
long long int PD[5100];
int tam;

// long long int f(int level) {
//   if (PD[level] != -1)
//     return PD[level];

//   // passei dos limites
//   if (level >= tam)
//     PD[level] = 1;
//   // última letra
//   else if (level == tam - 1)
//     PD[level] = 1;
//   // 27 -- 99
//   else if ( ((input[level] - '0') >= 3) || ((input[level] - '0') == 2 && (input[level + 1] - '0') >= 7)  ) {
//     PD[level] = f(level + 1);
//   }
//   else {
//     // 10 ou 20
//     if ( input[level + 1] == '0' )
//       PD[level] = f(level + 2);
//     // 11 a 19, 21 a 26
//     else {
//       PD[level] = f(level + 1) + f(level + 2);
//     }
//   }
  
//   return PD[level];
// }

long long int f(int level) {
  if (PD[level] != -1)
    return PD[level];

  if (level >= tam)
    return 1;

  if (input[level] == '0')
    return 0;

  long long int ret = 0;
  ret += f(level + 1);
  // 10 a 26
  if ( ((level + 1) < tam) && (10 * (input[level] - '0') + (input[level + 1] - '0')) <= 26 )
    ret += f(level + 2);

  return PD[level] = ret;
}

int main() {
  while( scanf("%[^\n]\n", input) ) {
    tam = strlen(input);
    if (input[0] == '0' && tam == 1)
      break;

    memset(PD, -1, sizeof PD);

    // printf("%lld\n", f(0) + 1);
    printf("%lld\n", f(0));
  }

  return 0;
}
  
