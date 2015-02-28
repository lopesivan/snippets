#include <cstdio>
#include <cstring>
#include <deque>

#define BACK 1
#define FRONT 0

using namespace std;

#define MAX (100001+100)
char input[MAX];

void process()
{
	int i, tam = strlen(input),style=BACK;
	
	deque<char> output;
	deque<char> ::iterator it;
	
	for (i=0; i < tam; i++)
	{
		if (input[i] == '[')
			style = FRONT;
		
		else if (input[i] == ']')
			style = BACK;
		
		else
			style == FRONT? output.push_front( input[i] ) : output.push_back( input[i] );
	}
}

int main()
{
	while ( fgets(input,MAX,stdin) != NULL)
	{
		input[strlen(input)-1]='\0';
		process();
	}
	
	return 0;
}