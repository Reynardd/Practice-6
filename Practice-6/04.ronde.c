#include <stdio.h>
int mostRepeatedDigitCount(char number[9]) {
    int mostRepeated = 0;
    int digits[10];
    for (int i = 0; i < 10; i++) { digits[i] = 0; }
    for (int i = 0; i < 9; i++)
    {
        int d = (int)(number[i]);
        digits[d - 48]++;
    }
    for (int i = 0; i < 10; i++) { if (digits[i] > mostRepeated) { mostRepeated = digits[i]; } }
    return mostRepeated;
}
int mostSequentialDigitCount(char number[9]) {
    char currentChar = number[0];
    int most = 0;
    int counter = 0;
    for (int i = 0; i < 9; i++)
    {
        if (currentChar == number[i])
        {
            counter++;
            if (counter > most) { most = counter; }
            continue;
        }
        counter = 1;
        currentChar = number[i];
    }
    return most;
}
int isPalindrome(char number[9]){
    for (int i = 0; i <= 4; i++){if (number[i] != number[7 - i]) { return 0; }}
    return 1;
}
int main() {
    char string[9];
    int t;
    scanf("%d\n", &t);
    for (; t > 0; t--)
    {
        fgets(string, 9, stdin);
        int flag = 0;
        if (mostRepeatedDigitCount(string) >= 4) { flag = 1; }
        else if (mostSequentialDigitCount(string) >= 3) { flag = 1; }
        else if (isPalindrome(string)) { flag = 1; }
        printf((flag) ? "Ronde!\n" : "Rond Nist\n");
        scanf("\n");
    }
}
