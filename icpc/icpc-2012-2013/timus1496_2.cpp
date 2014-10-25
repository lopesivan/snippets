#include <cstdio>
#include <map> /*dicionário*/
#include <string>

#define MAX (30+10)

/*1. header sem .h Ademais, os de c puro chamar com c antes*/

using namespace std; /*rotina padrão*/


map <string, int> dicionario;
map <string, int> :: iterator i;


int main()
{
	int n;
	char input[MAX];
	
	scanf("%d",&n);
	
	/*constroi dicionario*/
	while (n--)
	{
		scanf("%s%*c",input);
		dicionario[input]++;
	}
	
	/*percorre dicionário e toma os que possuem int maior que 1*/
	for (i = dicionario.begin(); i!=dicionario.end(); i++)
	{
		if (i -> second > 1)
			printf("%s\n", i -> first.c_str());
	}
	
	return 0;
}