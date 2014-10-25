#include <stdio.h>
#include <string.h>
#define MAX (10000)
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	char input[20];
	int TC, n, i, j, ans, pans;
	int v[MAX];
	int pd[MAX], out[MAX], k;
	scanf("%d%*c%*c", &TC);

	while (TC--) {

		n = 0;
		while ( gets(input) != NULL && strlen(input) ) {
			sscanf(input, "%d", &v[n++]);			
		}

		/*pd[i]: representa o tamanho da maior subseq que termina em i*/
		for (i = 0, ans = 0; i < n; ++i) {
			pd[i] = 1;
			for (j = 0; j < i; ++j) {
				if (v[i] > v[j])
					pd[i] = max(pd[i], pd[j] + 1);
			}
			if (pd[i] > ans) {
				ans = pd[i];
				pans = i;
			}
		}

		printf("Max hits: %d\n", ans);

		k = ans - 1;
		out[k--] = v[pans];
		
		for (i = ans - 1; i > 0; --i) {
			for (j = pans - 1; j >= 0; --j) {
				if (pd[j] == i) {
					pans = j;	
					break;
				}
			}
			out[k--] = v[pans];
		}

		for (i = 0; i < ans; ++i)
			printf("%d\n", out[i]);

		if (TC)
			puts("");
	}
	return 0;
}
