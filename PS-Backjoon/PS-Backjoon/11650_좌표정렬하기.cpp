#include <stdio.h>

struct Node {
	int x, y;
} heap[100001];
int N;

bool isBigger(int a, int b) {
	return (heap[a].x > heap[b].x) || ((heap[a].x == heap[b].x) && (heap[a].y > heap[b].y));
}

void heapSort(){
	// 모든 노드를 순회하면서, 현재 노드를 기준으로 위쪽으로 올라가며 Heapify
	for (int i = 1; i < N; i++) {
		int current = i;		while (current > 0 && isBigger(current, (current - 1) / 2))	{			Node temp = heap[(current - 1) / 2];			heap[(current - 1) / 2] = heap[current];			heap[current] = temp;			current = (current - 1) / 2;		}
	}
	// 크기 줄여가며 정렬	for (int i = N - 1; i >= 0; --i) {
		Node temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int current = 0;		while (current * 2 + 1 < i)		{			int child;			if (current * 2 + 2 == i) child = current * 2 + 1;			else child = isBigger(current * 2 + 1, current * 2 + 2) ? current * 2 + 1 : current * 2 + 2;

			if (isBigger(current, child)) {				break;			}

			Node temp = heap[current];			heap[current] = heap[child];			heap[child] = temp;
			current = child;		}	}}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d %d", &heap[i].x, &heap[i].y);

	heapSort();

	for (int i = 0; i < N; ++i) printf("%d %d\n", heap[i].x, heap[i].y);
}