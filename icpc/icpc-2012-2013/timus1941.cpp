#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int hash(char *s) {
  int x=0;
  int c;
  c = s[0] - 33; /*0 a 89*/
  x += c;
  c = (s[1]-33)*90;
  x += c;
  c = (s[2]-33)*90*90;
  x += c;
  return x;
}

void printset(multiset<int>::iterator ita, multiset<int>::iterator itb) {
  for (; ita != itb; ++ita) {
    printf("%d ", *ita);
  }
  puts("");
}

int main() {
  multiset<int> input;
  char c, letra[3];
  unsigned int i,answer=0;
  bool end = 0;

  while(scanf("%s%c",letra,&c)) {
    input.insert(hash(letra));
    if (c == '\n')
      break;
  }

  multiset<int> aux;
  queue<int> track;

  for (i = 0; i < input.size(); ++i) {
    scanf("%s%c",letra,&c);
    int tmp = hash(letra);
    track.push(tmp);
    aux.insert(tmp);
    if (c=='\n') {
      end = 1;
      break;
    }
  }

  //printset(input.begin(), input.end());
  //printset(aux.begin(), aux.end());

  if(input==aux) {
    ++answer;
  }

  int elem=track.front(); track.pop();
  aux.erase(aux.find(elem));

  while(!end && scanf("%s%c",letra,&c)==2) {
    int tmp = hash(letra);
    track.push(tmp);
    aux.insert(tmp);
    
    if(input==aux) {
      ++answer;
    }

    int elem=track.front(); track.pop();
    aux.erase(aux.find(elem));

    if (c=='\n')
      break;
  }

  printf("%d\n",answer);

  return 0;
}
