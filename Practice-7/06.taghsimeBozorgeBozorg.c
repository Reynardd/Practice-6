#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
int sign(char ch[100]) { return !(ch[0] - '-') ? -1 : 1; }
int intLen(int num[100]) {
    int i;
    for (i = 0; i < 100; i++) {
        if (num[i])break;
    }
    return 100 - i;
}
int isBigger(int num1[100], int num2[100]) {
    for (int i = 0; i < 100; i++)
    {
        if (num1[i] < num2[i]) { return 0; }
        if (num1[i] > num2[i]) { return 1; }
    }
    return 2;
}
void arrange(int num[53], int index) {
    if (num[index] >= 10)
    {
        num[index - 1] += num[index] / 10;
        num[index] %= 10;
    }
    if (num[index] < 0)
    {
        num[index] += 10;
        num[index - 1]--;
    }
}
void strToInt(char input[100], int target[100]) {
    int length = strlen(input);
    int i = 0;
    int index = 0;
    for (; i < length; i++) {
        char ch = input[length - i - 1];
        if (ch < 58 && ch>47) { target[99 - index] = ch - '0'; index++; }
    }
    for (int j = 0; j < 100 - index; j++) { target[j] = 0; }
}
void print(int num[100]) {
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {

        if (num[i] == 0 && !flag) { continue; }
        flag = 1;
        printf("%d", num[i]);
    }
    //printf("\n");
}
void sum(int number1[100], int number2[100], int result[100]) {
    for (int i = 0; i < 100; i++) { result[i] = 0; }
    for (int i = 99; i >= 0; i--)
    {
        result[i] += number1[i] + number2[i];
        arrange(result, i);
    }
}
int subtraction(int number1[100], int number2[100], int result[100]) {
    if (isBigger(number1, number2))
    {
        if (isBigger(number1, number2) == 2) {
            result[99] = 0;
            return 0;
        }
        for (int i = 99; i >= 0; i--)
        {
            result[i] += number1[i] - number2[i];
            arrange(result, i);
        }
        return 0;
    }
    else
    {

        for (int i = 99; i >= 0; i--)
        {
            result[i] += number2[i] - number1[i];
            arrange(result, i + 1);
        }
        return 1;
    }
}
void multiplyByNthPowerOf10(int num[100], int n) {
    int tmp[100] = { 0 };
    for (int i = 0; i < 100; i++) { tmp[i] = num[i]; }
    for (int i = 0; i < 100; i++) { num[i] = 0; }
    for (int i = 99; i >= 0; i--)
    {
        if (i - n < 0)continue;
        num[i - n] = tmp[i];
    }
}
void multiply(int num[52], int n, int res[100]) {
    for (int i = 51; i >= 0; i--)
    {
        res[i + 48] += n * num[i];
        arrange(res, i + 48);
    }
}
void multiple(int num[100], int n, int res[100]) {
    for (int i = 99; i >= 0; i--)
    {
        res[i] += n * num[i];
        arrange(res, i);
    }
}
void getFirstNDigit(int num[100], int n, int res[100]) {
    int counter = 0;
    int flag = 1;
    for (int i = 0; i < 100; i++)
    {
        if (counter == n) { return; }
        if (flag && !num[i]) { continue; }
        flag = 0;
        res[100 - n + counter] = num[i];
        counter++;
    }
}
void deleteFirstNDigit(int num[100], int n) {
    int deleted = 0;
    int flag = 1;
    for (int i = 0; i < 100; i++)
    {
        if (deleted == n) { return; }
        if (flag && !num[i]) { continue; }
        flag = 0;
        num[i] = 0;
        deleted++;
    }
}
void set(int input[100], int target[100]) { for (int i = 0; i < 100; i++) { target[i] = input[i]; } }
void numberFix(int num[100], int digitCount) {
    int tmp[100] = { 0 };
    for (int i = 0; i < digitCount; i++)
    {
        tmp[100 + i - digitCount] = num[i];
    }
    set(tmp, num);
}
int isZero(int num[100]) {
    for (int i = 0; i < 100; i++) { if (num[i])return 0; }
    return 1;
}
void divide(int number1[53], int number2[53], int cont) {
    int result[100] = { 0 };
    int decimalPart[100];
    if (isZero(number1))
    {
        printf("0");
        return;
    }
    if (!isBigger(number1, number2))
    {
        printf("0");
        set(number1, decimalPart);
    }
    //int s = sign(num1) * sign(num2);
    //if (s < 0)printf("-");
    int index = 0;
    int earlyDigitCount = intLen(number1);
    int allCheckedDigits = 0;
    int answerDigitCount = 0;
    int addZero = 0;
    int remainLen = 0;

    while (isBigger(number1, number2))
    {
        int firstNDIgits[100] = { 0 };
        int nDigits = 1;
        while (1) {
            getFirstNDigit(number1, nDigits, firstNDIgits);
            if (isBigger(firstNDIgits, number2)) { break; }
            nDigits++;
            if (nDigits > remainLen + 1 && addZero) { result[index++] = 0; answerDigitCount++; }
            for (int i = 0; i < 100; i++) { firstNDIgits[i] = 0; }
        }
        addZero = 1;
        int i = 1;
        for (; i < 10; i++)
        {
            int tmp[100] = { 0 };
            multiple(number2, i, tmp);
            int bigger = isBigger(tmp, firstNDIgits);
            if (bigger) { if (bigger == 1) { i--; }  break; }
        }
        if (i == 10)i--;
        result[index++] = i;
        answerDigitCount++;
        int tmp1[100] = { 0 };
        int tmp2[100] = { 0 };
        int tmp3[100] = { 0 };
        multiple(number2, i, tmp3);
        subtraction(firstNDIgits, tmp3, tmp1);
        remainLen = intLen(tmp1);
        set(tmp1, decimalPart);
        multiplyByNthPowerOf10(tmp1, intLen(number1) - nDigits);
        deleteFirstNDigit(number1, nDigits);
        sum(number1, tmp1, tmp2);
        set(tmp2, number1);
        allCheckedDigits += nDigits - remainLen;
    }
    numberFix(result, answerDigitCount);
    multiplyByNthPowerOf10(result, earlyDigitCount - allCheckedDigits - intLen(number1));
    print(result);
    if (!isZero(decimalPart) && cont)
    {
        printf(".");
        while (!isZero(decimalPart))
        {
            multiplyByNthPowerOf10(decimalPart, 1);
            divide(decimalPart, number2, 0);
        }
    }
}
int main() {
    char sNumber1[100], sNumber2[100];
    int n1[100], n2[100];
    scanf("%s\n%s", sNumber1, sNumber2);
    strToInt(sNumber1, n1);
    strToInt(sNumber2, n2);
    divide(n1, n2, 1);
}