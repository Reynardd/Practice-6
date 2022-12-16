#include <stdio.h>
#include <string.h>
#include <math.h>
void arrange(int num[53], int index) {
    if (num[index] >= 10)
    {
        num[index - 1]+=num[index]/10;
        num[index] %= 10;
    }
}
void strToInt(char input[53], int target[52]) {
    int length = strlen(input);
    int i = 0;
    for (; i < length; i++) {
        target[51 - i] = input[length - i - 1] - '0';
    }
    for (int j = 0; j < 52 - i; j++) { target[j] = 0; }
}
void print(int num[100]) {
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {

        if (num[i] == 0 && !flag) { continue; }
        flag = 1;
        printf("%d", num[i]);
    }
    printf("\n");
}
void sum(int number1[100], int number2[100],int result[100]) {
    for (int i = 99; i >= 0; i--)
    {
        result[i] += number1[i] + number2[i];
        arrange(result, i );
    }
}
void multiply(int num[52], int n,int res[100]) {
    for (int i = 51; i >= 0; i--)
    {
        res[i + 48] += n * num[i];
        arrange(res, i + 48);
    }
}
void multiplyByNthPowerOf10(int num[100], int n) {
    int tmp[100] = { 0 };
    for (int i = 0; i < 100; i++) { tmp[i] = num[i]; }
    for (int i = 0; i < 100; i++) { num[i] = 0; }
    for (int i = 99; i >=0; i--)
    {
        if (i - n < 0 )continue;
        num[i-n]=tmp[i];
    }
}
void mul(char num1[53], char num2[53]) {
    int number1[52], number2[52], result[100] = {0};
    for (int i = 0; i < 53; i++) { result[i] = 0; }
    strToInt(num1, number1);
    strToInt(num2, number2);

    for (int i = 51; i >=0; i--)
    {
        int tmp1[100] = {0};
        //printf("---------------\nPower: %d\n", 51 - i);
        multiply(number1, number2[i], tmp1);
        //print(tmp1);
        multiplyByNthPowerOf10(tmp1, 51-i);
        int res[100] = { 0 };
        sum(result, tmp1, res);
        for (int i = 0; i < 100; i++) { result[i] = res[i]; }
        //print(tmp1);
        //print(result);
    }
    print(result);
}
int main() {
    char sNumber1[53], sNumber2[53];
    scanf("%s\n%s", sNumber1, sNumber2);
    mul(sNumber1, sNumber2);
}