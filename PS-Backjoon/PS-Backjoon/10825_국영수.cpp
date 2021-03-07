#include <stdio.h>

int N;
struct Student {
	char name[11];
	int korean, english, math;
} student[100001];

int mstrcmp(const char *a, const char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] != b[i]) return a[i] - b[i];
	}
	return a[i] - b[i];
}

bool compare(int a, int b) {
	if (student[a].korean < student[b].korean) return true;
	else if (student[a].korean > student[b].korean) return false;

	if (student[a].english > student[b].english) return true;
	else if (student[a].english < student[b].english) return false;

	if (student[a].math < student[b].math) return true;
	else if (student[a].math > student[b].math) return false;

	if (mstrcmp(student[a].name, student[b].name) > 0) return true;
	else return false;
}

void heapSort() {
	for (int i = 1; i < N; ++i) {
		int current = i;		while (current > 0 && compare(current, (current - 1) / 2)) {			Student temp = student[(current - 1) / 2];			student[(current - 1) / 2] = student[current];			student[current] = temp;			current = (current - 1) / 2;		}
	}

	for (int i = N - 1; i >= 0; --i) {
		Student temp = student[0];
		student[0] = student[i];
		student[i] = temp;

		int current = 0;		while (current * 2 + 1 < i)	{			int child;			if (current * 2 + 2 == i) child = current * 2 + 1;			else child = compare(current * 2 + 1, current * 2 + 2) ? current * 2 + 1 : current * 2 + 2;			
			if (compare(current, child)) break;

			Student temp = student[current];			student[current] = student[child];			student[child] = temp;
			current = child;		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) scanf("%s %d %d %d", student[i].name, &student[i].korean, &student[i].english, &student[i].math);

	heapSort();

	for (int i = 0; i < N; ++i) printf("%s\n", student[i].name);
}