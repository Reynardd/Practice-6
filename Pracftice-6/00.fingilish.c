#include <stdio.h>
#include <math.h>
int vowelCount(char word[7]){
    int counter=0;
    for (int i = 0; i < 7; i++)
    {    
        if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='u'||word[i]=='o')
        {
            counter++;
        }
        
    }
    return counter;   
}
int main(){
    char word[7];
    scanf("%s",word);
    printf("%d",(int)pow(2,vowelCount(word)));
}
