#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int minScore;
	int* scores = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int score;
		scanf("%d", &score);
		if (k-1==i){minScore = score;}
		*(scores+i) = score;
	}
	int c = 0;
	for (int i = 0; i <n; i++) { if (minScore <= *(scores + i) && *(scores + i) != 0) { c++; } }
	printf("%d", c);
}
