/*
  Problem Judge: SPOJ
  http://www.spoj.com/problems/MATSUM/
  Solved with a 2D-BIT.
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

template<class T>
class fenwick2d {

private:
  const int tamx,tamy;		//dimensions of the tree
  vector< vector< T > > t;	//both start from 1

public:

  //construtor
  fenwick2d(int tamx, int tamy) : tamx(tamx), tamy(tamy), t(vector<vector<T> >(tamx+1, vector<T>(tamy+1,0))){};

  //destrutor
  ~fenwick2d(){};

  //returns the cumulative sum from index (1,1) to (x,y), that is, A[1][1] + A[1][2] + ... + A[1][y] + A[2][1] + A[2][2] + ... + A[2][y] + ... + A[x][1] + A[x][2] + ... + A[x][y]
  //O(log x * log y)
  T query(int x, int y) {
    T sum = 0;
    while (x > 0) {
      int y1 = y;
      while (y1 > 0) {
	sum += t[x][y1];
	y1 -= y1 & -y1;
      }
      x -= x & -x;
    }
    return sum;
  }

  //less code version
  // T query(int x, int y) {
  //   T sum = 0;
  //   for ( ; x > 0; x -= x & -x)
  //     for (int y1 = y; y1 > 0; sum += t[x][y1], y1 -= y1 & -y1);
  //   return sum;
  // }

  //returns the cumulative sum from index (x1,y1) to (x2,y2)
  T query(int x1, int y1, int x2, int y2) {

    // printf("%d ", query(x2,y2));
    // printf("- %d ", (y1 == 1 ? 0 : query(x2,y1-1)));
    // printf("- %d ", (x1 == 1 ? 0 : query(x1-1,y2)));
    // printf("+ %d =\n", (x1 == 1 || y1 == 1 ? 0 : query(x1-1,y1-1)));
    return query(x2,y2) - \
      (y1 == 1 ? 0 : query(x2,y1-1)) - \
      (x1 == 1 ? 0 : query(x1-1,y2)) + \
      (x1 == 1 || y1 == 1 ? 0 : query(x1-1,y1-1));
  }
  
  //adds _x to index (x,y)
 void update(int x, int y, int _x) {
    while (x <= tamx) {
      int y1 = y;
      while (y1 <= tamy) {
	t[x][y1] += _x;
	y1 += y1 & -y1;
      }
      x += x & -x;
    }
  }

  //less code version
  // void update(int x, int y, int _x) {
  //   for ( ; x <= tamx; x += x & -x)
  //     for (int y1 = y; y1 <= tamy; t[x][y1] += _x, y1 += y1 & -y1);
  // }

  //prints the tree vector (for debugging purposes)
  void print() {
    line();
    printf("tamx = %d, tamy = %d\n", tamx, tamy);
    printf("t vector:\n");
    for (int i = 1; i <= tamx; ++i, puts(""))
      for (int j = 1; j <= tamy; ++j)
	printf("%2d ", t[i][j]);
    line();
  }

  void print2() {
    line();
    printf("tamx = %d, tamy = %d\n", tamx, tamy);
    printf("content of the fenwick tree:\n");
    for (int i = 1; i <= tamx; ++i, puts(""))
      for (int j = 1; j <= tamy; ++j)
	printf("%2d ", query(i,j,i,j));
    line();
  }

  void line() {
    puts("----------------------------------------");
  }
  //returns the size of this fenwick tree
  pair<int,int> get_size() {
    return pair<int,int>(tamx,tamy);
  }
};

//this has to be better improved ==> several tests have to be added here
int main() {
  int TC;
  scanf("%d", &TC);
  char tmp[10];

  while (TC--) {
    int n,a,b,c,d;
    scanf("%d", &n);
    fenwick2d<int> f(n,n);

    while (scanf("%s",tmp), strcmp(tmp, "END")) {
      if(!strcmp(tmp,"SET")) {
	scanf("%d%d%d", &a, &b, &c);
	++a,++b;
	f.update(a,b,- f.query(a,b,a,b) + c);
      }
      else {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	++a,++b,++c,++d;
	printf("%d\n", f.query(a,b,c,d));
      }
    }
    puts("");
  }
  
  return 0;
}
