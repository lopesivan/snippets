/*
  Sample Input:
  53241
  abced
  
  Sample Output:
  12345
  abcde
  
*/

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* Sorts s using snail sort, calling next_permutation repeteadly, until it is false. */
void snail_sort(char *input);

void snail_sort(char *input) {
  int tam = strlen(input);
  while( next_permutation(input, input + tam) );
}

template<typename T>
void snail_sort_generic(T begin, T end) {
  while (next_permutation(begin, end) );
}

int main() {
  char input[50];
  
  while( scanf("%[^\n]\n", input) == 1 ) {
    snail_sort(input);
    // snail_sort_generic(input, input + strlen(input));
    puts(input);
  }
  
  return 0;
}
