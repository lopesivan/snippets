#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int main()
{
	map<string, string> dict;
	map<string, string> ::iterator id;
	multiset<char> buffer;
	multiset<char> :: iterator it;
	char input[20];
	string s;
	int tam, i, count;
	
	while( gets(input) )
	{
		if ( !strcmp(input, "XXXXXX") )
			break;
		
		tam = strlen(input);
		buffer.clear();
		s.clear();
		
		for (i = 0; i < tam; i++)
			buffer.insert( input[i] );
		
		for (it = buffer.begin(); it!= buffer.end(); ++it)
			s += *it;
		
		dict[input] = s;
	}
	
	/*for (id = dict.begin(); id!= dict.end(); ++id)
		printf("%s %s\n", (id->first).c_str(), (id->second).c_str());
	puts("");*/
	
	while( gets(input) )
	{
		if ( !strcmp(input, "XXXXXX") )
			break;
		
		count = 0;
		tam = strlen(input);
		buffer.clear();
		s.clear();
		
		for (i = 0; i < tam; i++)
		buffer.insert( input[i] );
		
		for (it = buffer.begin(); it!= buffer.end(); ++it)
			s += *it;
		
		for (id = dict.begin(); id!= dict.end(); ++id)
		{
			if (s == id->second)
			{
				puts(id->first.c_str());
				count = 1;
			}
		}
		
		count == 1 ? puts("******") : puts("NOT A VALID WORD\n******");
	}
	
	return 0;
}