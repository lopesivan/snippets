#include <stdio.h>

int main() {
	int h, m, _h, _m, answer;

	while (scanf("%d%d%d%d", &h, &m, &_h, &_m), h || m || _h || _m ) {
		if (h == _h && m == _m)
			printf("1440\n");

		else {
			if (_m >= m)
				answer = _m - m;
			else {
				answer = (_m - m + 60)%60;
				h = (h+1)%24;
			}
			answer += ((_h-h+24)%24)*60;

			printf("%d\n", answer);
		}

	}
	return 0;
}

