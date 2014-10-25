#include <stdio.h>

int main() {
	int h, w, next, last, i, answer;

	while (scanf("%d%d", &h, &w), h || w) {
		scanf("%d", &next);
		answer = h - next;

		for (i = 1; i < w; ++i) {
			last = next;
			scanf("%d", &next);
			if (next < last)
				answer += last - next;
		}
		printf("%d\n", answer);
	}
	return 0;
}

