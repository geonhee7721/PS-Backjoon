#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX	100003
#define MAX_LEN		21

int N, M;
int mstrcmp(const char *a, const char *b) {
	int i;
	for (i = 0; a[i] != '\0'; i++) if (a[i] != b[i])return a[i] - b[i];
	return a[i] - b[i];
}
void mstrcpy(char *dest, const char *src) {
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

struct Node {
	int index;
	char name[MAX_LEN];
	Node* next;
} node[MAX_INDEX];
Node* hashTable[MAX_INDEX];

int index = 1;

Node* alloc(char name[]) {
	mstrcpy(node[index].name, name);
	node[index].index = index;
	return &node[index++];
}

unsigned long hash(const char *str) {	unsigned long hash = 5381;	int c;
	while (c = *str++)	hash = (((hash << 5) + hash) + c) % MAX_INDEX;
	return hash % MAX_INDEX;}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		char name[MAX_LEN];
		scanf("%s", name);

		int key = hash(name);
		Node* newNode = alloc(name);
		newNode->next = hashTable[key];
		hashTable[key] = newNode;
	}

	for (int i = 0; i < M; ++i) {
		char input[MAX_LEN];
		scanf("%s", input);

		if (input[0] >= 'A' && input[0] <= 'Z') {
			int key = hash(input);
			for (Node* pp = hashTable[key]; pp; pp = pp->next) if (mstrcmp(input, pp->name) == 0) {
				printf("%d\n", pp->index);
				break;
			}
		}
		else {
			printf("%s\n", node[atoi(input)].name);
		}
	}
}