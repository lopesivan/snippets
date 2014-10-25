#include <cstdio>
#include <cstdlib>
#include <queue>
#define abs(i, j) ((i) >= (j)? (i-j) : (j-i))
#define MAX (500+10)

using namespace std;

int main()
{
	int TC, n, v[MAX];
	scanf("%d", &TC);

	while (TC--) {
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) 
			scanf("%d", &v[i]);

		priority_queue<int> pq;

		for (int i = 0; i < n; ++i) {
			int soma = 0;
			for (int j = 0; j < n; ++j) {
				soma += abs(v[i], v[j]);
			}
			pq.push(-soma);
		}

		printf("%d\n", -pq.top() );
	}
	return 0;
}
