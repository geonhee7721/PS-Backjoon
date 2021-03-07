#include <cstdio>
using namespace std;
int a[20];
int ans, N, K;

void recursion(int sum, int index) {
	if (index == N) {
		if (sum == 0) {
			ans += 1;
		}
		return;
	}
	recursion(sum - a[index], index + 1);
	recursion(sum, index + 1);
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	recursion(K, 0);
	if (K == 0)  ans -= 1;
	printf("%d\n", ans);

	return 0;
}
