#include <stdio.h>
int colorCount(char word[6],char color){
    int c=0;
    for (int i = 0; i < 6; i++)
    {
        if (word[i]==color)
        {
            c++;
        }
    }
    return c;
}
void n(){printf("nakhor lite");}
void b(){printf("rahat baash");}
int main(){
    char tag[6];
    scanf("%s",tag);
    int g=colorCount(tag,'G');
    int r=colorCount(tag,'R');
    int y=5-g-r;
    if (r>=3)n();
    else if (r>=2 && y>=2)n();
    else if (r+y==5) n();\
    else b();
}
