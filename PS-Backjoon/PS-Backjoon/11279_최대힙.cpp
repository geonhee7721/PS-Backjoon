﻿#include <stdio.h>

int heap[100001];
int N;
int heapSize = 0;

void heapPush(int value){
	heap[heapSize] = value;
	int current = heapSize;	while (current > 0 && heap[current] > heap[(current - 1) / 2]) {		int temp = heap[(current - 1) / 2];		heap[(current - 1) / 2] = heap[current];		heap[current] = temp;		current = (current - 1) / 2;	}
	heapSize = heapSize + 1;}

int heapPop(){	if (heapSize <= 0) return 0;

	int value = heap[0];	heapSize = heapSize - 1;
	heap[0] = heap[heapSize];
	int current = 0;	while (current * 2 + 1 < heapSize) {		int child;		if (current * 2 + 2 == heapSize) child = current * 2 + 1;		else child = heap[current * 2 + 1] > heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;

		if (heap[current] > heap[child]) break;

		int temp = heap[current];		heap[current] = heap[child];		heap[child] = temp;
		current = child;	}	return value;}

int main() {
	scanf("%d", &N);
	int value;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &value);

		if (value == 0) printf("%d\n", heapPop());
		else heapPush(value);
	}
	return 0;
}