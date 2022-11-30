#include <stdio.h>
int greenCount(char word[6]){
    int c=0;
    for (int i = 0; i < 6; i++)
    {
        if (word[i]=='G')
        {
            c++;
        }
    }
    return c;
}
int redCount(char word[6]){
    int c=0;
    for (int i = 0; i < 6; i++)
    {
        if (word[i]=='R')
        {
            c++;
        }
    }
    return c;
}
void n(){
    printf("nakhor lite");
}
void b(){
    printf("rahat baash");
}
int main(){
    char tag[6];
    scanf("%s",tag);
    int g=greenCount(tag);
    int r=redCount(tag);
    int y=5-g-r;
    if (r>=3)n();
    else if (r>=2 && y>=2)n();
    else if (r+y==5) n();\
    else b();
}
