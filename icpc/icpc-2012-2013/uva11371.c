#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp( const void *a, const void  *b) {
    char *c = (char*) a;
    char *d = (char*) b;
    
    return *c - *d;
}

int main()
{
    int i, tam;
    long long int a, _a, diff;
    char s[20], _s[20];
    
    while (scanf("%s", s) == 1) {

	/*231*/
	qsort(s, strlen(s), sizeof s[0], cmp);
	strcpy(_s, s);
	tam = strlen(s);
	for (i = 0; i < tam; ++i) {
	    _s[i] = s[tam-1-i];
	}
	
	i = 0;
	while (s[i] == '0')
	    i++;
	
	if (i) {
	    s[0] = s[i];
	    s[i] = '0';
	}
	
	sscanf(_s, "%lld", &_a);
	sscanf(s, "%lld", &a);
	
	diff = _a - a;
	printf("%lld - %lld = %lld = 9 * %lld\n", _a, a, diff, diff/9);
	
    }
    
    return 0;
}