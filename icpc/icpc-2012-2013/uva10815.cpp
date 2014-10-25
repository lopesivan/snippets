#include <algorithm>
#include <string>
#include <set>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

std::set<string> dict;
std::set<string>:: iterator it;

int main()
{
	char input[50],aux[50];
	unsigned int tam,i,j;
	
	while(scanf("%s",input) != EOF)
	{
		tam = strlen(input);
		
		for (i=0, j=0; i<tam; i++)
		{
			if (isalpha(input[i]))
				aux[j++]=tolower(input[i]);
			
			else if (j>0)
			{
				aux[j]='\0';
				dict.insert(aux);
				j=0;
			}
		}
		
		if (j>0)
		{
			aux[j]='\0';
			dict.insert(aux);
		}
	}
	
	for (it=dict.begin(); it!=dict.end(); it++)
		printf("%s\n",(*it).c_str());
	
	return 0;
}