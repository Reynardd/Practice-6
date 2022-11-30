#pragma warning (disable:4996)
#include <stdio.h>
#include <math.h>
int isPrime(int n) {
    if (n <= 1) { return 0; }
    for (int i = 2; i < n; i++) { if (n%i==0)return 0;}
    return 1;
}
int nthPrime(int n) {
    int c = 0;
    int num = 0;
    while (1) {
        if (isPrime(num)) { c++; }
        if (c == n)return num;
        num++;
    }
}
int nthNamousanPrime(int n) { return nthPrime(nthPrime(n)); }
int main() {
    int n;
    scanf("%d", &n);
    for (int i =0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        printf("%d\n",nthNamousanPrime(m));
    }
}
