#include <stdio.h>
#include <string.h>
int isBigger(int a[52], int b[52]) {
    for (int i = 0; i < 52; i++) {
        if (a[i] < b[i]) { return 0; }
        if (a[i] > b[i]) { return 1; }
    }
    return 2;
}
void arrange(int num[53], int index) {
    if (num[index] < 0)
    {
        num[index - 1]--;
        num[index] += 10;
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
void print(int num[53]) {
    int flag = 0;
    for (int i = 0; i < 53; i++)
    {

        if (num[i] == 0 && !flag) { continue; }
        flag = 1;
        printf("%d", num[i]);
    }
    printf("\n");
}
void subtraction(char num1[53], char num2[52]) {
    int number1[52], number2[52], result[53];
    for (int i = 0; i < 53; i++) { result[i] = 0; }
    strToInt(num1, number1);
    strToInt(num2, number2);
    if (isBigger(number1, number2))
    {
        if (isBigger(number1, number2) == 2) {
            printf("0\n");
            return;
        }
        for (int i = 51; i >= 0; i--)
        {
            result[i + 1] += number1[i] - number2[i];
            arrange(result, i + 1);
        }
        print(result);
    }
    else
    {

        for (int i = 51; i >= 0; i--)
        {
            result[i + 1] += number2[i] - number1[i];
            arrange(result, i + 1);
        }
        printf("-");
        print(result);
    }

}
int main() {
    char sNumber1[53], sNumber2[53];
    gets(sNumber1);
    gets(sNumber2);
    subtraction(sNumber1, sNumber2);
}