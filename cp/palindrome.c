#include <stdio.h>

int main()
{
    char s1[20],s2[20]={'\0'};
    int i,len=0,flag=0;
    printf("Enter string: ");
    scanf("%s",s1);
    for(i=0;s1[i]!='\0';i++)
    {
        len++;
    }
    for(i=len-1;i>=0;i--)
    {
        s2[len-i-1]=s1[i];
    }
    for(i=0;i<len;i++)
    {
        if (s1[i]!=s2[i])
            flag=1;
    }
    if(flag==0)
        printf("It is a palindrome");
    else    
        printf("It is not a palindrome");
}