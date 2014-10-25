#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	char input[60];
	string s;
	
	while ( scanf("%s", input), s=input, s != "#" )
		next_permutation ( s.begin(), s.end() ) == false ? puts("No Successor") : 	puts(s.c_str());
	
	return 0;
}