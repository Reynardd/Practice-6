#include <stdio.h>
#include <ctype.h>
void toTitle(char string[1001]) {
    char last = '\0';
    string[0]=toupper(string[0]);
    for (int i = 1; i < 1001; i++)
    {
        last = string[i - 1];
        if (!string[i]) { return; }
        if (last == ' ') { string[i]=toupper(string[i]); }
        else string[i]=tolower(string[i]);
    }
}
int main() {
    char string[1001];
    int n;
    scanf("%d\n",&n);
    for (int i = 0; i < n; i++)
    {
        fgets(string, 1001, stdin);
        toTitle(string);
        printf("%s\n", string);
    }

}
