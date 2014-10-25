#include <stdio.h>
#include <stdlib.h>
#define teto(x) (int)(((x)-(int)(x)) == 0? (x) : (x) + 1)

int main() {
	int v[7], ans;
	
	while (scanf("%d%d%d%d%d%d", &v[1], &v[2], &v[3], &v[4], &v[5], &v[6]), v[1] || v[2] || v[3] || v[4] || v[5] || v[6]) {
				
		ans = v[6] + v[5] + v[4] + teto((float) v[3]/4);
		
		v[1] -= v[5] * 11;
		v[2] -= v[4] * 5;
		
		switch (v[3] % 4)
		{
			case 1:
				v[2] -= 5;
				v[1] -= 7;
				break;
			case 2:
				v[2] -= 3;
				v[1] -= 6;
				break;
			case 3:
				v[2] -= 1;
				v[1] -= 5;
				break;
		}
		
		if (v[2] < 0)
			v[1] += v[2] * 4;
		
		if (v[1] < 0)
			v[1] = 0;
		if (v[2] < 0)
			v[2] = 0;
		
		ans += teto ( (float) (v[1] + v[2]*4) / 36 );
		
		printf("%d\n", ans);
	}
	
	return 0;
}