#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	pair<int,int> a;
	int t, i, next, maior, j;
	char input[110];
	multimap<int, string> dict;
	multimap<int, string> ::iterator it;
	multimap<int, string> ::reverse_iterator rit;
	
	scanf("%d", &t);
	
	for (j = 1; j <= t; ++j)
	{
		dict.clear();
		
		for (i = 0; i < 10; ++i)
		{
			scanf("%s %d", input, &next);
			dict.insert ( pair<int, string>(next,input) );
		}
		
		
		rit = dict.rbegin();
		maior = rit -> first;
		
		while(1)
		{
			++rit;
			
			if (rit == dict.rend() )
			{
				--rit;
				break;
			}
			
			if ((rit -> first) < maior)
			{
				--rit;
				break;
			}
		}
		
		printf("Case #%d:\n", j);
		while ( rit != dict.rbegin() )
		{
			cout << (rit->second) << endl;
			--rit;
		}
		cout << (rit->second) << endl;
	}
	
	return 0;
}