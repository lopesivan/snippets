#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> letras;
	set<char> output;
	set<char> ::iterator it;
	char input[100000];
	int tam, maior, i;
	
	while ( gets(input) )
	{
		tam = strlen(input);
		letras.assign(257,0);
		output.clear();
		
		//preencher (ASCII: hash)
		for (i = 0; i < tam; i++)
			letras[input[i]]++;
		
		maior = -1;
		
		//maior
		for (i = (int)'A'; i<= (int)'z'; i++)
			maior = max(maior, letras[i]);
		
		//encontrar chaves maiores
		for (i = (int)'A'; i<= (int)'z'; i++)
			if (letras[i] == maior)
				output.insert((char)i);
		
		//imprime
		for (it = output.begin(); it != output.end(); it++)
			putchar(*it);
		
		printf(" %d\n", maior);
		
	}
	
	return 0;
}