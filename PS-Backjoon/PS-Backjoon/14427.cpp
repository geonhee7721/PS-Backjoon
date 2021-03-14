#include <stdio.h>

struct Node {
	int heapIndex;
	int num;
} node[100001];
int nodeIndex = 1;

int heap[100001];
int heapSize = 0;

int compare(int a, int b) {
	return (node[a].num < node[b].num) || (node[a].num == node[b].num && a < b);
}

void downdate(int current) {
	while (current * 2 + 1 < heapSize) {
		int child;
		if (current * 2 + 2 == heapSize) child = current * 2 + 1;
		else child = compare(heap[current * 2 + 1], heap[current * 2 + 2]) ? current * 2 + 1 : current * 2 + 2;

		if (compare(heap[current], heap[child])) break;

		int temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		node[heap[current]].heapIndex = current;
		node[heap[child]].heapIndex = child;

		current = child;
	}
}

void update(int current) {
	while (current > 0 && compare(heap[current], heap[(current - 1) / 2])) {
		int root = (current - 1) / 2;
		int temp = heap[root];
		heap[root] = heap[current];
		heap[current] = temp;

		node[heap[current]].heapIndex = current;
		node[heap[root]].heapIndex = root;

		current = root;
	}
}

void heapPush(int index) {
	heap[heapSize] = index;
	node[index].heapIndex = heapSize;
	update(heapSize);
	heapSize++;
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		scanf("%d", &node[nodeIndex].num);

		heapPush(nodeIndex);

		nodeIndex++;
	}

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int query;
		scanf("%d", &query);

		if (query == 1) {
			int fromIndex, toValue;
			scanf("%d %d", &fromIndex, &toValue);

			node[fromIndex].num = toValue;
			update(node[fromIndex].heapIndex);
			downdate(node[fromIndex].heapIndex);
		}
		else if (query == 2) {
			printf("%d\n", heap[0]);
		}
	}
}