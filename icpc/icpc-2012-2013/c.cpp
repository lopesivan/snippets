#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 110;

int main() {
  int TC;
  int n;
  vector<string> v;
  char input[MAX];
  scanf("%d", &TC);

  while(TC--) {
    scanf("%d\n", &n);
    v = vector<string>();

    for (int i = 0; i < n; ++i) {
      scanf("%[^\n]\n", input);
      v.push_back(input);
    }

    int cost = 0;
    // insertion sort
    for (int i = 0; i < n; ++i) {
      bool flag = false;
      for (int j = i; j > 0; --j) {
        //        if ( strcmp(v[j-1].c_str(), v[j].c_str()) > 0) {
        if (v[j-1] > v[j]) {
          swap(v[j], v[j-1]);
          flag = true;
        }
        else
          break;
      }
      if (flag)
        ++cost;
    }

    // for (int i = 0; i < n; ++i)
    //   puts(v[i].c_str());

    printf("%d\n", cost);
  }

  return 0;
}
