#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <iostream>
#define point pair<double,double>
const double PI = 3.14159265358979;
const double sp = 60, mp = 3600, hp = 43200;
using namespace std;

inline double distance(double x1, double y1, double x2, double y2) {
  double diffx = fabs(x1 - x2);
  double diffy = fabs(y1 - y2);
  return sqrt(diffx*diffx + diffy*diffy);
}

// double distance(point a, point b) {
//   return distance(a.first,a.second,b.first,b.second);
// }

inline int secondsfromm(int h, int m, int s) {
  h %= 12;
  int ret = s;
  ret += 60*m;
  ret += 3600*h;
  return ret;
}


inline point rect(double angle, double size) {
  point p;
  p.first = (size/2) * cos(angle);
  p.second = (size/2) * sin(angle);

  return p;
}

inline double angleh(int h, int m, int s) {
  h %= 12;
  double aux = secondsfromm(h,m,s);

  return (PI/2) - (aux/hp)*2*PI;
}

inline double anglem(int h, int m, int s) {
  h %= 12;
  double aux = secondsfromm(0,m,s);

  return (PI/2) - (aux/mp)*2*PI;
}

inline double angles(int h, int m, int s) {
  h %= 12;
  double aux = secondsfromm(0,0,s);

  return (PI/2) - (aux/sp)*2*PI;
}

inline int plush(int h, int m, int s) {
  if (m==59 && s==59)
    ++h;
  return h % 24;
}

inline int plusm(int h, int m, int s) {
  if (s==59)
    ++m;
  return m % 60;
}

inline int pluss(int h, int m, int s) {
  ++s;
  return s % 60;
}

inline point cm(point a, point b, point c, int w1, int w2, int w3) {
  int sum = w1+w2+w3;
  
  double x = (a.first*w1 + b.first*w2 + c.first*w3)/sum;
  double y = (a.second*w1 + b.second*w2 + c.second*w3)/sum;

  return make_pair(x,y);
}

inline void print_pair(point a) {
  printf("Point: x = %.2lf, y = %.2lf\n",a.first,a.second);
}

int main() {
  int l1,l2,l3,w1,w2,w3,h1,h2,m1,m2,s1,s2;
  while (scanf("%d%d%d%d%d%d %d:%d:%d %d:%d:%d", &l1, &l2, &l3, &w1, &w2, &w3, &h1, &m1, &s1, &h2, &m2, &s2) == 12) {

    double ans = 0;

    int h3=plush(h1, m1, s1);
    int m3=plusm(h1, m1, s1);
    int s3=pluss(h1, m1, s1);

    if (h1 == h2 && m1 == m2 && s1 == s2)
      goto end;

    for (;;)
    {
      point cm1,cm2, a, b, c;

      a = rect(angleh(h1,m1,s1),l1);
      b = rect(anglem(h1,m1,s1),l2);
      c = rect(angles(h1,m1,s1),l3);
      cm1 = cm(a,b,c,w1,w2,w3);

      a = rect(angleh(h3,m3,s3),l1);
      b = rect(anglem(h3,m3,s3),l2);
      c = rect(angles(h3,m3,s3),l3);
      cm2 = cm(a,b,c,w1,w2,w3);

      // print_pair(cm1);
      // print_pair(cm2);

      ans += distance(cm1.first,cm1.second,cm2.first,cm2.second);

      // printf("%d:%d:%d %d:%d:%d\n", h2, m2, s2, h3, m3, s3);
      if (h2==h3 && s2==s3 && m2==m3)
	break;

      h1=plush(h1,m1,s1);
      m1=plusm(h1,m1,s1);
      s1=pluss(h1,m1,s1);

      h3=plush(h3,m3,s3);
      m3=plusm(h3,m3,s3);
      s3=pluss(h3,m3,s3);
    }
  end:
    printf("%.2lf\n", ans);
  }
  return 0;
}
