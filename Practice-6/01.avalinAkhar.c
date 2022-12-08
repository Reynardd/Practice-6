#include <stdio.h>
char lastChar(char word[51]){
    char last;
    for (int i = 0; i < 51; i++)
    {
        if (word[i]=='\0')
        {
            return last;
        }
        last=word[i];
        
    }
    return last;
}
int main(){
    char stringA[51];
    char stringB[51];
    scanf("%s",stringA);
    scanf("%s",stringB);
    printf((stringA[0]==lastChar(stringB))?"YES":"NO");
}
