#include <stdio.h>

int main()
{
    char s1[20],s2[20];
    int i=0,j=0;
    printf("Enter a string: ");
    scanf("%s",s1);
    printf("Enter another string: ");
    scanf("%s",s2);
    while (s1[i]!='\0')
        i++;
    s1[i]=' ';
    i++;
    while(s2[j]!='\0')
    {
        s1[i]=s2[j];
        i++,j++;
    }
    s1[i]='\0';
    printf("%s",s1);
}