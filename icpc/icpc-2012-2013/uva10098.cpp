#include <algorithm>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	string s;
	
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		cin >> s;
		
		sort( s.begin(), s.end() );
		
		do
		{
			puts( s.c_str() );
		} while ( next_permutation( s.begin(), s.end() ) );
		
		puts("");
	}
	
	return 0;
}