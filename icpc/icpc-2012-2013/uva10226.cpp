#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int t;
	char input[35];
	double sum;
	map<string, int> dict;
	map<string, int> ::iterator it;
	
	scanf("%d%*c%*c", &t);
	
	while (t--)
	{
		dict.clear();
		sum = 0;
		
		while ( gets(input) )
			if ( strlen(input) )
				dict[input]++, sum++;
			else
				break;
			
		for (it = dict.begin(); it!= dict.end(); ++it)
			printf("%s %.4lf\n", it->first.c_str(), ((it->second)/sum)*100);
		
		if (t)
			puts("");
	}
	
	return 0;
}