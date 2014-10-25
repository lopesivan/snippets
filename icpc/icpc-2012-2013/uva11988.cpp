#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <list>

#define MAX (100001+100)

using namespace std;

int main()
{
	string buffer;
	list<string> output;
	list<string> ::iterator it;
	char input[MAX];
	int i, style;
	
	while( gets(input) )
	{
		output = list<string> ();
		buffer = string();
		i = -1;
		style = 1;
		
		while (input[++i])
		{
			switch( input[i] )
			{
				case ']':
					style == 1? output.push_back(buffer) : output.push_front(buffer);
					buffer = string();
					style = 1;
					break;
				case '[':
					style == 1? output.push_back(buffer) : output.push_front(buffer);
					buffer = string();
					style = 0;
					break;
				default:
					buffer += input[i];
			}
		}
		
		style == 1? output.push_back(buffer) : output.push_front(buffer);
		
		for (it = output.begin(); it!= output.end(); ++it)
			printf("%s",(*it).c_str());
		puts("");
	}
	
	return 0;
}