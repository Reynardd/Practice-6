#pragma warning (disable:4996)
#include <stdio.h>
#include <math.h>
int numberLength(int n) {
    int d = 0;
    while (n > 0)
    {
        d++;
        n /= 10;
    }
    return d;
}
void intToStr(int n, char number[5]) {
    for (int i = 0; i < numberLength(n); i++)
    {
        number[i] = n / (int)pow(10, numberLength(n) - i - 1) % 10 + 48;
    }
    for (int i = numberLength(n); i < 5; i++) { number[i] = '\0'; }
}
int isPrime(int n) {
    if (n <= 1) { return 0; }
    for (int i = 2; i < n; i++) { if (n%i==0)return 0;}
    return 1;
}
int isTooPrime(int number) {
    if (!isPrime(number)) { return 0; }
    char n[5];
    intToStr(number, n);
    for (int i = 0; i < 4; i++)
    {
        if (n[i] == '\0') { break; }
        if (!isPrime(n[i] - 48)) { return 0; }
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; i++)
    {
        if (isTooPrime(i)) { printf("%d ", i); }
    }
}
