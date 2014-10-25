#include <cstdio>
#include <map>
#include <string>
 
using namespace std;
 
map<string, int> dic;
map<string, int>::iterator it;
 
char nm[1000];
 
int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    scanf("%s", nm);
    dic[nm]++;
  }
  for(it = dic.begin(); it != dic.end(); ++it)
    if (it->second > 1)
      printf("%s\n", it->first.c_str());
}