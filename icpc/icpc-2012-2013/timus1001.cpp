#include <cstdio>
#include <cmath>

double s[(270000/2)];

int main() {
	unsigned long long int e;
	
	int i = 0;
	
	while( scanf("%lld", &e) == 1 ) {
		s[i++] = sqrt( (double) e);
	}
	
	for (--i; i >= 0; --i) {
		printf("%.4lf\n", s[i]);
	}
	
	
	return 0;
}