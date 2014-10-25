# include <cstdio>
# include <string>
# include <cstring>

using namespace std;

char m[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string reversed (string s)
{
	string t;
	int i;
	int tam = s.size();
	
	for (i = 0; i < tam; ++i)
		t += s[tam-1-i];
	
	t+='\0';
	
	
	return t;
}

string converteBase(int x, int b)
{
	string s;
	
	while (x != 0)
	{
		s += m[ x%b ];
		x /= b;
	}
	
	return reversed(s);
}

int main() {
	int valores[100];
	int dif = 7, nQ, numero, nCasos;
	double matBases[100];
	char convertido[100];
	
	scanf("%d", &nCasos);
	for(int caso = 0; caso < nCasos; caso++) {
		printf("Case %d:\n", caso + 1);
		for(int i = 0; i < 36; ++i) scanf("%d", &valores[i]);
		scanf("%d", &nQ);
		for(int m = 0; m < nQ; m++) {
			scanf("%d", &numero);
			double custo, menorCusto = 1000000;
			for(int base = 2; base <= 36; ++base) {
				custo = 0;
				strcpy(convertido, converteBase(numero, base).c_str());
				for(int indice = 0; indice < strlen(convertido); ++indice) {
					if ('0' <= convertido[indice] && convertido[indice] <= '9') {
						custo += valores[convertido[indice] - '0'];
					}
					else {
						custo += valores[convertido[indice] - dif - '0'];
					}
				}
				matBases[base] = custo;
				if (custo < menorCusto) menorCusto = custo;
			}
			
			printf("Cheapest base(s) for number %d:", numero);
			
			for(int k = 2; k <= 36; ++k) {
				if (matBases[k] == menorCusto) printf(" %d", k);
			}
			printf("\n");
		}
		if (caso != nCasos - 1) printf("\n");
	}
	return 0;
}