#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main()
{
	map<string, string> dict;
	map<string, string> ::iterator it;
	char antes[20], depois[20], line[50];
	
	while(gets(line))
	{
		if ( !strlen(line) )
			break;
		else
			sscanf(line,"%s%s", antes, depois);
		dict[depois]=antes;
	}
	
	while ( gets(depois) )
	{
		if (dict.find(depois) != dict.end())
			cout << dict[depois] << endl;
		else
			puts("eh");
	}
	
	return 0;
}