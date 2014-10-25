#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  map<string,string> db;
  map<string,int> logged;
  char s1[100], s2[100], s3[100];
  while(n--) {
    scanf("%s %s ", s1, s2);
    
    if ( !strcmp("register", s1 ) ) {
      scanf("%s\n", s3);
      if ( db.find(s2) == db.end() ) {
	db[s2]=s3;
	logged[s2] = 0;
	puts("success: new user added");
      }
      else {
	puts("fail: user already exists");
      }
    }
    else if (!strcmp("login", s1) ) {
      scanf("%s\n", s3);
      if (db.find(s2) == db.end() ) {
	puts("fail: no such user");
      }
      else if ( strcmp(db[s2].c_str(),s3) ) {
	puts("fail: incorrect password");
      }
      else if ( logged[s2] == 1 )
	puts("fail: already logged in");
      else {
	logged[s2] = 1;
	puts("success: user logged in");
      }
    }
    else { //logout
      if (db.find(s2) == db.end() )
	puts("fail: no such user");
      else if (logged[s2] == 0)
	puts("fail: already logged out");
      else {
	logged[s2] = 0;
	puts("success: user logged out");
      }
    }
  }
  return 0;
}
