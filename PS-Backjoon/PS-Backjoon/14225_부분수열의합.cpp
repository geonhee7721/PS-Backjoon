#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int s[21];
bool SUM[2 << 20];

void f(int index, int sum) {
	if (index == N) {
		SUM[sum] = true;
		return;
	}

	f(index + 1, sum + s[index]);
	f(index + 1, sum);
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &s[i]);
	}

	f(0, 0);

	for (int ret = 1; ; ret++) {
		if (SUM[ret] == false) {
			printf("%d", ret);
			break;
		}
	}

	return 0;
}