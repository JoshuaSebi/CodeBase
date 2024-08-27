#include <stdio.h>

int main()
{
    char s1[20],c,rep;
    int i,flag=0;
    printf("Enter string: ");
    scanf("%s",s1);       
    printf("Enter the character to be replaced: ");
    scanf(" %c",&c);
    printf("Enter new character: ");
    scanf(" %c",&rep);
    for (i=0;s1[i]!='\0';i++)
    {
        if (s1[i]==c)
        {
            s1[i]=rep;
            flag=1;
        }
    }
    if (flag==1)
    {
        printf("Modified string is - %s",s1);
    }
    else
        printf("Character not found");
}

