#include <stdio.h>

int N;
int minHeap[100001];
int maxHeap[100001];
int minHeapSize = 0;
int maxHeapSize = 0;

void minHeapPush(int value) {
	minHeap[minHeapSize] = value;
	int current = minHeapSize;	while (current > 0 && minHeap[current] < minHeap[(current - 1) / 2]) {		int temp = minHeap[(current - 1) / 2];		minHeap[(current - 1) / 2] = minHeap[current];		minHeap[current] = temp;		current = (current - 1) / 2;	}
	minHeapSize++;}

void maxHeapPush(int value) {
	maxHeap[maxHeapSize] = value;
	int current = maxHeapSize;	while (current > 0 && maxHeap[current] > maxHeap[(current - 1) / 2]) {		int temp = maxHeap[(current - 1) / 2];		maxHeap[(current - 1) / 2] = maxHeap[current];		maxHeap[current] = temp;		current = (current - 1) / 2;	}
	maxHeapSize++;}

void minHeapify() {
	int current = 0;	while (current * 2 + 1 < minHeapSize)	{		int child;		if (current * 2 + 2 == minHeapSize) child = current * 2 + 1;		else child = minHeap[current * 2 + 1] < minHeap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;		
		if (minHeap[current] < minHeap[child]) break;		
		int temp = minHeap[current];		minHeap[current] = minHeap[child];		minHeap[child] = temp;
		current = child;	}}

void maxHeapify() {
	int current = 0;	while (current * 2 + 1 < maxHeapSize)	{		int child;		if (current * 2 + 2 == maxHeapSize) child = current * 2 + 1;		else child = maxHeap[current * 2 + 1] > maxHeap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
		if (maxHeap[current] > maxHeap[child]) break;
		int temp = maxHeap[current];		maxHeap[current] = maxHeap[child];		maxHeap[child] = temp;
		current = child;	}}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int value;
		scanf("%d", &value);

		if (maxHeapSize == minHeapSize) 
			maxHeapPush(value);
		else 
			minHeapPush(value);

		if (maxHeapSize > 0 && minHeapSize > 0 && maxHeap[0] > minHeap[0]) {
			int temp = maxHeap[0];
			maxHeap[0] = minHeap[0];
			minHeap[0] = temp;

			minHeapify();
			maxHeapify();
		}

		printf("%d\n", maxHeap[0]);
	}
}