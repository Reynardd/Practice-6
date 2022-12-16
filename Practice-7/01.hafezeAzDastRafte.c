#include <stdio.h>
int array[100000];
int* f(int n) {
    for (int i = 0; i < n; i++)
    {
        array[i] = i * i;
    }
    return array;
}
int main() {
    int n;
    scanf("%d", &n);
    int* b = f(n);
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
}